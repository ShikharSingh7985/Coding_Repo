/*
Intuition:

This problem asks us to count the number of subarrays
that contain exactly k odd numbers.

A subarray is called "nice" if it has exactly k odd numbers.

Main idea:

Convert the problem into binary form:

odd number  -> 1
even number -> 0

Now the problem becomes:

Count subarrays whose sum is exactly k.

This is very similar to:
Leetcode 930: Binary Subarrays With Sum

Why?

Because if odd = 1 and even = 0,
then a subarray with exactly k odd numbers
will have sum k.

We use sliding window.

window_sum stores number of odd numbers in current window.

prefix_zeros counts how many even numbers are present
at the beginning of the current valid window.

Why prefix_zeros is needed?

Example:
nums = [2, 4, 1, 3]
k = 2

After converting:
[0, 0, 1, 1]

When window sum becomes 2, valid window is:
[0, 0, 1, 1]

But starting even numbers do not affect odd count,
so these are also valid:

[0, 1, 1]
[1, 1]

So count += 1 + prefix_zeros

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        // Counts even numbers at the beginning of current valid window
        int prefix_zeros = 0;

        // Stores number of odd numbers in current window
        int window_sum = 0;

        // Stores total number of nice subarrays
        int count = 0;

        // i is left pointer, j is right pointer
        int i = 0, j = 0;

        // Traverse array using right pointer
        while (j < nums.size()) {

            // Transform:
            // odd number contributes 1
            // even number contributes 0
            window_sum += nums[j] % 2;

            /*
            Shrink window from left while:
            1. Starting element is even, because removing it
               does not change odd count and gives extra valid subarrays.
            2. OR window_sum > k, because we have more than k odd numbers.
            */
            while (i < j && ((nums[i] % 2 == 0) || window_sum > k)) {

                // If we remove an odd number,
                // prefix even count should reset
                if (nums[i] % 2 == 1) {
                    prefix_zeros = 0;
                }

                // If we remove an even number,
                // it creates one extra possible starting point
                else {
                    prefix_zeros++;
                }

                // Remove nums[i]'s contribution from window sum
                window_sum -= nums[i] % 2;

                // Move left pointer forward
                i++;
            }

            // If current window has exactly k odd numbers
            if (window_sum == k) {

                // Count current window + extra windows formed
                // by removing prefix even numbers
                count += 1 + prefix_zeros;
            }

            // Move right pointer forward
            j++;
        }

        // Return total number of nice subarrays
        return count;
    }
};