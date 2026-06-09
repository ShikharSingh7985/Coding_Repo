/*
Intuition:

We need to find the maximum number of consecutive 1s
if we are allowed to flip at most k zeroes into 1s.

This is a sliding window problem.

Main idea:

We maintain a window from j to i.

Inside this window, we allow at most k zeroes.

Whenever nums[i] is 1:
- It can be included directly in the window.

Whenever nums[i] is 0:
- If k > 0, we flip this zero and include it.
- If k == 0, we need to shrink the window from the left side
  until we remove one previous zero from the window.

After removing one zero, the current zero can be considered inside the window.

At every step, we calculate:

length = i - j + 1

and update maxlen.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        // sz stores size of nums array
        int sz = nums.size();
    
        // j is the starting point of sliding window
        int j = 0;

        // i is the ending point of sliding window
        int i = 0;

        // maxlen stores maximum valid window length
        int maxlen = 0;

        // len stores current window length
        int len = 0;

        // Traverse array using i pointer
        while(i < sz) {

            // If current element is 1,
            // simply include it in the current window
            if(nums[i] == 1) {

                // Current window length
                len = i - j + 1;

                // Update maximum length
                maxlen = max(maxlen, len);
            }

            // If current element is 0
            else if(nums[i] == 0) {

                // If we still have flips available
                if(k > 0) {

                    // Include this zero by flipping it
                    len = i - j + 1;

                    // Use one flip
                    k--;

                    // Update maximum length
                    maxlen = max(maxlen, len);
                }

                // If no flips are left
                else if(k <= 0) {

                    // Move j until we find a zero
                    // This removes one previously flipped zero
                    while(nums[j] != 0) {
                        j++;
                    }

                    // Move j one more step to remove that zero from window
                    j++;
                }
            }

            // Move right pointer forward
            i++;
        }

        // Return maximum consecutive 1s after at most k flips
        return maxlen;
    }
};