/*
Intuition:

This problem asks us to count subarrays whose sum is equal to goal.

Since nums contains only 0s and 1s, we can use a sliding window.

Main idea:

We maintain a window from i to j.

window_sum stores the sum of current window.

If window_sum becomes greater than goal,
we move i forward to reduce the window.

But there is one special thing:

Zeros at the beginning of a valid window create extra valid subarrays.

Example:
nums = [0, 0, 1, 0, 1]
goal = 2

When window sum becomes 2, suppose window is:
[0, 0, 1, 0, 1]

This is valid.

But because starting zeros do not affect the sum,
these are also valid:

[0, 1, 0, 1]
[1, 0, 1]

So prefix_zeros counts how many zeros are present at the beginning
of the current valid window.

Whenever window_sum == goal:
count += 1 + prefix_zeros

1 is for the current full window.
prefix_zeros is for extra windows after removing starting zeros.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        // Counts zeros at the beginning of current valid window
        int prefix_zeros = 0;

        // Stores sum of current window
        int window_sum = 0;

        // Stores total number of subarrays with sum equal to goal
        int count = 0;
        
        // i is left pointer, j is right pointer
        int i = 0, j = 0;
        
        // Move right pointer through the array
        while(j < nums.size()) {

            // Add current element into window sum
            window_sum += nums[j];
            
            /*
            Shrink window from left while:
            1. i < j
            2. Either nums[i] is 0, because starting zeros can be removed
               and counted as extra valid subarrays
            3. Or window_sum > goal, because window sum is too large
            */
            while (i < j && (nums[i] == 0 || window_sum > goal)) {

                // If we remove a 1, prefix zeros reset
                // because valid starting zero count breaks
                if (nums[i] == 1) {
                    prefix_zeros = 0;
                }

                // If we remove a 0, it can create one extra valid subarray
                else {
                    prefix_zeros += 1;
                }
                
                // Remove nums[i] from window sum
                window_sum -= nums[i];

                // Move left pointer forward
                i++;
            }
            
            // If current window sum is equal to goal
            if (window_sum == goal) {

                // Count current window + extra windows formed by prefix zeros
                count += 1 + prefix_zeros;
            }

            // Move right pointer forward
            j++;
        }
        
        // Return total valid subarrays
        return count;
    }
};