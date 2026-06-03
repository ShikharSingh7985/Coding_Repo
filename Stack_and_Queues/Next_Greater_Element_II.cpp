/*
Intuition:

This is Next Greater Element Part 2.

In this problem, the array is circular.

That means after the last element, we again consider elements from the beginning.

Example:
nums = [1, 2, 1]

For first 1:
next greater = 2

For 2:
there is no greater element, so -1

For last 1:
because array is circular, after last 1 we can again check from start.
So next greater = 2

Answer:
[2, -1, 2]

Main idea:

Use monotonic stack.

Since the array is circular, we virtually traverse the array two times.

Instead of actually creating a double array, we use:

i % n

So index:
0, 1, 2, 3, 4, 5

For n = 3:
i % n becomes:
0, 1, 2, 0, 1, 2

We traverse from right to left from 2*n - 1 to 0.

Why right to left?

Because for every element, we want to know the next greater element on its right side.

Steps:

1. Traverse from 2*n - 1 to 0.
2. Remove all elements from stack that are smaller than or equal to nums[i % n].
3. If i < n, then we are in the real array range:
   - If stack is empty, answer is -1.
   - Else answer is stack.top().
4. Push nums[i % n] into stack.

Time Complexity: O(2n) = O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        // n stores size of nums
        int n = nums.size();

        // ans stores final next greater elements
        vector<int> ans(n, -1);

        // stack stores possible next greater elements
        stack<int> st;

        // Traverse circular array from right to left
        // We go from 2*n-1 to 0 to simulate circular behavior
        for(int i = 2 * n - 1; i >= 0; i--) {

            // Actual index in nums using modulo
            int idx = i % n;

            // Remove all smaller or equal elements
            // because they cannot be next greater for nums[idx]
            while(!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }

            // Store answer only for original array indexes
            if(i < n) {

                // If stack is empty, no greater element exists
                if(st.empty()) {
                    ans[idx] = -1;
                }

                // Otherwise stack top is next greater element
                else {
                    ans[idx] = st.top();
                }
            }

            // Push current element into stack
            st.push(nums[idx]);
        }

        // Return final answer
        return ans;
    }
};