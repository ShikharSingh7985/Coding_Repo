/*
Intuition:

We need to find the sum of minimum values of all subarrays.

Brute force would generate all subarrays and find minimum,
but that would take O(n^2) or more.

Better idea:

Instead of thinking:
"For every subarray, find minimum"

Think:
"For every arr[i], count in how many subarrays arr[i] is the minimum"

Then contribution of arr[i] will be:

arr[i] * number of subarrays where arr[i] is minimum

To find this count, we need:

1. NSL: nearest smaller element index on left
2. NSR: nearest smaller element index on right

For index i:

d1 = i - NSL[i]
Number of choices to start subarray from left side.

d2 = NSR[i] - i
Number of choices to end subarray on right side.

Total subarrays where arr[i] is minimum:

d1 * d2

Contribution:

arr[i] * d1 * d2

Why one side strict and one side non-strict?

To handle duplicate elements correctly.

For NSL:
We remove elements greater than arr[i].
So left side keeps smaller or equal element.

For NSR:
We remove elements greater than or equal to arr[i].
So right side keeps strictly smaller element.

This avoids counting the same subarray multiple times.

Time Complexity: O(n)
Space Complexity: O(n)
*/

typedef unsigned long long ll;

class Solution {
public:
    
    // Function to find nearest smaller element index on left side
    // Similar concept to Leetcode 84: Largest Rectangle in Histogram
    vector<int> getNSL(vector<int>& arr, int n) {

        // result[i] stores index of nearest smaller element on left of arr[i]
        vector<int> result(n);

        // stack stores indexes
        stack<int> st;
        
        // Traverse from left to right
        for(int i = 0; i < n; i++) {

            // If stack is empty, no smaller element exists on left
            if(st.empty()) {
                result[i] = -1;
            } 
            
            else {

                // Remove all elements greater than current element
                // We need nearest smaller or equal element on left
                while(!st.empty() && arr[st.top()] > arr[i])
                    st.pop();
                
                // If stack is empty, no smaller element exists
                // Otherwise stack top is nearest smaller/equal element index
                result[i] = st.empty() ? -1 : st.top();
            }

            // Push current index into stack
            st.push(i);
        }
        
        return result;
    }
    
    // Function to find nearest smaller element index on right side
    // Similar concept to Leetcode 84: Largest Rectangle in Histogram
    vector<int> getNSR(vector<int>& arr, int n) {

        // result[i] stores index of nearest smaller element on right of arr[i]
        vector<int> result(n);

        // stack stores indexes
        stack<int> st;
        
        // Traverse from right to left
        for(int i = n - 1; i >= 0; i--) {

            // If stack is empty, no smaller element exists on right
            if(st.empty()) {
                result[i] = n;
            } 
            
            else {

                // Remove all elements greater than or equal to current element
                // We need strictly smaller element on right
                while(!st.empty() && arr[st.top()] >= arr[i])
                    st.pop();
                
                // If stack is empty, no smaller element exists
                // Otherwise stack top is nearest smaller element index
                result[i] = st.empty() ? n : st.top();
            }

            // Push current index into stack
            st.push(i);
        }
        
        return result;
    }
    
    int sumSubarrayMins(vector<int>& arr) {

        // n stores size of array
        int n = arr.size();
        
        // NSL[i] stores nearest smaller index on left of arr[i]
        vector<int> NSL = getNSL(arr, n);

        // NSR[i] stores nearest smaller index on right of arr[i]
        vector<int> NSR = getNSR(arr, n);
        
        // sum stores final answer
        ll sum = 0;

        // Modulo value given in question
        int M = 1e9 + 7;

        // Calculate contribution of every element
        for(int i = 0; i < n; i++) {

            // Number of choices for starting point of subarray
            ll d1 = i - NSL[i];

            // Number of choices for ending point of subarray
            ll d2 = NSR[i] - i;
            
            /*
                d1 choices on left side
                d2 choices on right side

                Total subarrays where arr[i] is minimum:
                d1 * d2
            */
            ll total_ways_for_i_min = d1 * d2;

            // Total contribution of arr[i]
            ll sum_i_in_total_ways = arr[i] * total_ways_for_i_min;
            
            // Add contribution into answer with modulo
            sum = (sum + sum_i_in_total_ways) % M;
        }
        
        // Return final sum
        return sum;
    }
};