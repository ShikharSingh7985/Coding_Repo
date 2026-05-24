/**
 * Intuition:
 *
 * Method 1:
 * Use hashing/map to store visited nodes with a timer/index.
 * If a node appears again, then loop length =
 * current timer - first stored timer of that node.
 *
 * Method 2:
 * Use slow and fast pointers.
 *
 * Step 1:
 * Detect whether a loop exists using Floyd's Cycle Detection Algorithm.
 * slow moves 1 step and fast moves 2 steps.
 *
 * Step 2:
 * If slow and fast meet, a loop exists.
 *
 * Step 3:
 * To find loop length, keep one pointer fixed at the meeting point.
 * Move the other pointer one step at a time until it comes back
 * to the same meeting point.
 *
 * Count the number of steps taken.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        
        // slow pointer moves one step at a time
        Node* slow = head;

        // fast pointer moves two steps at a time
        Node* fast = head;

        // flag tells whether loop exists or not
        bool flag = false;

        // length stores the length of the loop
        int length = 1;
        
        // Detect loop using slow and fast pointers
        while(fast != NULL && fast->next != NULL) {
            
            slow = slow->next;
            fast = fast->next->next;
            
            // If slow and fast meet, loop exists
            if(slow == fast) {
                flag = true;
                break;
            }
        }
        
        // If no loop is found, return 0
        if(flag == false) return 0;

        else {
            // Move fast one step ahead from meeting point
            fast = fast->next;

            // Keep slow fixed and move fast until it comes back to slow
            while(slow != fast) {
                fast = fast->next;
                length++;
            }
        }

        // Return total number of nodes in the loop
        return length;
    }
};