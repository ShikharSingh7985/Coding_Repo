/*
Intuition:

This problem asks for the maximum number of fruits we can collect
using only 2 baskets.

Each basket can contain only one type of fruit.

So the problem becomes:

Find the longest subarray with at most 2 different numbers.

Main idea:

We maintain a window from j to i.

a and b store the two fruit types currently allowed.

If fruits[i] is either a or b:
- Current fruit can be included.
- Window is valid.
- Update maxlen.

If fruits[i] is a third fruit type:
- Current window from j to i-1 was valid.
- So first update maxlen using i - j.
- Then we need to create a new valid window.

To create the new window:
- Keep the last continuous block of fruits[i-1].
- Include the new fruit fruits[i].
- So new fruit types become fruits[i-1] and fruits[i].

Example:
fruits = [1, 2, 2, 2, 3]

When i reaches 3:
Previous fruit is 2.

We keep:
[2, 2, 2]

and include:
3

New window:
[2, 2, 2, 3]

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        // sz stores size of fruits array
        int sz = fruits.size();

        // If there are 0, 1, or 2 fruits,
        // we can collect all of them
        if (sz <= 2) return sz;

        // a stores first fruit type
        int a = fruits[0];

        // b stores second fruit type
        int b = fruits[1];

        // i is the right pointer of window
        int i = 2;

        // j is the left pointer of window
        int j = 0;

        // Since size is greater than 2,
        // minimum possible answer is 2
        int maxlen = 2;

        // Traverse from index 2
        while (i < sz) {

            // If current fruit belongs to one of the two baskets,
            // current window is valid
            if (fruits[i] == a || fruits[i] == b) {

                // Update maximum valid window length
                maxlen = max(maxlen, i - j + 1);
            }

            // If current fruit is a third type
            else {

                // Current valid window was from j to i-1
                // Its length is i - j
                maxlen = max(maxlen, i - j);

                // Start new window from previous index
                j = i - 1;

                // Move j backward to include the full continuous block
                // of previous fruit type
                while (j > 0 && fruits[j - 1] == fruits[i - 1]) {
                    j--;
                }

                // Now the two basket types become:
                // previous fruit type and current fruit type
                a = fruits[i - 1];
                b = fruits[i];
            }

            // Move right pointer forward
            i++;
        }

        // Return maximum fruits collected
        return maxlen;
    }
};