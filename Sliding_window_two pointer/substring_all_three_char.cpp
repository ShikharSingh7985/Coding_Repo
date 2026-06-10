/*
Intuition:

We need to count substrings that contain at least one 'a',
at least one 'b', and at least one 'c'.

Main idea:

Use sliding window.

We maintain a window from i to j.

arr[0] stores count of 'a'
arr[1] stores count of 'b'
arr[2] stores count of 'c'

For every j, we include s[j] in the window.

Whenever the current window contains all three characters,
that means substring from i to j is valid.

Now important point:

If s[i...j] is valid, then all substrings starting at i
and ending at j, j+1, j+2, ... sz-1 are also valid.

So number of valid substrings added will be:

sz - j

Then we shrink the window from left side by moving i.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int numberOfSubstrings(string s) {

        // arr[0] counts 'a', arr[1] counts 'b', arr[2] counts 'c'
        int arr[3] = {0};

        // sz stores length of string
        int sz = s.length();

        // i is left pointer of window
        int i = 0;

        // j is right pointer of window
        int j = 0;

        // count stores total valid substrings
        int count = 0;

        // Move right pointer through the string
        while (j < sz) {

            // Include current character in window
            if (s[j] == 'a') arr[0]++;
            else if (s[j] == 'b') arr[1]++;
            else if (s[j] == 'c') arr[2]++;

            // While current window contains at least one a, b, and c
            while (arr[0] > 0 && arr[1] > 0 && arr[2] > 0) {

                /*
                If substring s[i...j] is valid,
                then s[i...j], s[i...j+1], s[i...j+2] ... s[i...sz-1]
                are also valid.

                So add sz - j substrings.
                */
                count += (sz - j);

                // Remove s[i] from window before moving i
                if (s[i] == 'a') arr[0]--;
                else if (s[i] == 'b') arr[1]--;
                else if (s[i] == 'c') arr[2]--;

                // Shrink window from left
                i++;
            }

            // Move right pointer forward
            j++;
        }

        // Return total number of valid substrings
        return count;
    }
};