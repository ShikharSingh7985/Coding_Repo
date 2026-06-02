/*

Leetcode -155
Intuition:

We need to design a stack that supports these operations:
1. push()
2. pop()
3. top()
4. getMin()

All operations should work in O(1) time.

Normal stack can give push, pop, and top in O(1),
but it cannot give minimum element directly in O(1).

So we maintain one extra vector arr.

Main idea:

st stores the actual stack elements.

arr stores the minimum value till each position.

Example:
Push: 5, 3, 7, 2

st:
5 3 7 2

arr:
INT_MAX, 5, 3, 3, 2

So whenever we need minimum,
we simply return arr.back().

When we pop from stack,
we also pop from arr to keep both synchronized.

Time Complexity:
push: O(1)
pop: O(1)
top: O(1)
getMin: O(1)

Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:

    // st stores actual stack elements
    stack<int> st;

    // arr[i] stores the minimum value up to the i-th element
    vector<int> arr;

    MinStack() {

        // Initially push INT_MAX so that first minimum comparison works
        arr.push_back(INT_MAX); 
    }
    
    void push(int val) {

        // Push value into actual stack
        st.push(val);

        // Minimum till now will be minimum of current value
        // and previous minimum stored at arr.back()
        int f = min(val, arr.back()); 

        // Store current minimum
        arr.push_back(f);
    }
    
    void pop() {

        // If stack is not empty, remove element from both structures
        if (!st.empty()) {

            // Remove top element from actual stack
            st.pop();

            // Remove corresponding minimum value
            arr.pop_back();
        }
    }
    
    int top() {

        // Return top element of stack
        return st.top();
    }
    
    int getMin() {

        // Current minimum is always stored at last index of arr
        return arr.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */