/*

Leetcode - 20
Intuition:

We need to check whether the given bracket string is valid or not.

A valid bracket string means:
1. Every opening bracket must have a matching closing bracket.
2. Brackets must be closed in the correct order.

Example:
"()[]{}" is valid
"([{}])" is valid
"(]" is not valid
"([)]" is not valid

Main idea:

Use a stack.

Why stack?
Because the bracket that opens last should close first.

Example:
s = "({[]})"

Opening order:
( then { then [

Closing should happen in reverse order:
] then } then )

So stack is perfect because it follows LIFO:
Last In First Out.

Steps:
1. If current character is an opening bracket, push it into stack.
2. If current character is a closing bracket:
   - Stack should not be empty.
   - Top of stack should be the matching opening bracket.
   - If matched, pop it.
   - If not matched, return false.
3. At the end, stack should be empty.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isValid(string s) {

        // Stack stores opening brackets
        stack<char> st;

        // Traverse every character in the string
        for (char ch : s) {

            // If current character is an opening bracket,
            // push it into the stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            // Otherwise current character is a closing bracket
            else {

                // If stack is empty, there is no opening bracket
                // available for this closing bracket
                if (st.empty()) return false;

                // Get the top opening bracket
                char top = st.top();

                // Remove it from stack because we are going to match it
                st.pop();

                // Check whether current closing bracket matches
                // the last opening bracket or not
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // If stack is empty, all opening brackets were matched
        // If stack is not empty, some opening brackets are unclosed
        return st.empty();
    }
};