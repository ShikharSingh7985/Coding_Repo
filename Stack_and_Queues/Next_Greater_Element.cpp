/*

Leetcode -496
Intuition:

We need to find the next greater element of each element of nums1
based on its position in nums2.

For every element in nums2, we want to know:
"What is the first greater element on its right side?"

Example:
nums2 = [1, 3, 4, 2]

Next greater of 1 = 3
Next greater of 3 = 4
Next greater of 4 = -1
Next greater of 2 = -1

Main idea:

We traverse nums2 from right to left and use a stack.

The stack stores possible next greater elements.

For each nums2[i]:

1. Remove all smaller elements from stack,
   because they cannot be next greater for nums2[i].

2. After removing:
   - If stack is empty, next greater is -1.
   - Else stack top is the next greater element.

3. Store answer in map:
   mp[nums2[i]] = next greater element

4. Push nums2[i] into stack.

Finally, for every element in nums1,
we directly get its next greater element from map.

Time Complexity: O(n + m)
where n = nums2.size(), m = nums1.size()

Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // ans stores final answer for nums1
        vector<int> ans;

        // map stores next greater element for every element of nums2
        unordered_map<int,int> mp;

        // stack stores possible next greater elements
        stack<int> st;

        // length of nums2
        int l2 = nums2.size();

        // Traverse nums2 from right to left
        for(int i = l2 - 1; i >= 0; i--) {

            // If stack is empty, no greater element exists on right side
            if(st.empty()) {
                mp[nums2[i]] = -1;
                st.push(nums2[i]);
            }

            // If current element is smaller than stack top,
            // stack top is the next greater element
            else if(nums2[i] < st.top()) {
                mp[nums2[i]] = st.top();
                st.push(nums2[i]);
            }

            else {

                // Remove all smaller elements from stack
                // because they cannot be next greater
                while(!st.empty() && st.top() < nums2[i]) {
                    st.pop();
                }

                // If stack becomes empty, no greater element exists
                if(st.empty()) {
                    mp[nums2[i]] = -1;
                    st.push(nums2[i]);
                }

                // Otherwise stack top is the next greater element
                else {
                    mp[nums2[i]] = st.top();
                    st.push(nums2[i]);
                }
            }
        }

        // length of nums1
        int l1 = nums1.size();

        // Build answer for nums1 using map
        for(int i = 0; i < l1; i++) {

            // current element of nums1
            int ele = nums1[i];

            // stores next greater element of ele
            int vari;

            // If element exists in map, get its next greater element
            if(mp.find(ele) != mp.end()) {
                vari = mp[ele];
            }

            // Push answer into ans vector
            ans.push_back(vari);
        }

        // Return final answer
        return ans;
    }
};