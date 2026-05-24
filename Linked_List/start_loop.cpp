/**
 * Intuition:
 *
 * There are two common methods to detect the starting point of a cycle:
 *
 * Method 1:
 * Use a map/set to store visited nodes.
 * The first node that appears again is the starting point of the cycle.
 *
 * Method 2:
 * Use slow and fast pointers.
 *
 * Step 1:
 * Move slow by 1 step and fast by 2 steps.
 * If they meet, a cycle exists.
 *
 * Step 2:
 * After collision, place one pointer at head.
 * Keep the other pointer at the collision point.
 *
 * Step 3:
 * Move both pointers one step at a time.
 * The node where they meet again is the starting point of the cycle.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode *head) {

        // slow moves one step
        ListNode* slow = head;

        // fast moves two steps
        ListNode* fast = head;

        // flag tells whether cycle exists or not
        bool flag = false;

        // Step 1: Detect cycle using slow and fast pointers
        while(fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            // If slow and fast meet, cycle is present
            if(slow == fast) {
                flag = true;
                break;
            }
        }

        // If no cycle found, return NULL
        if(flag == false) return NULL;

        // Step 2: Find starting point of cycle
        else {

            // Start temp from head
            ListNode* temp = head;

            // Move temp and slow one step at a time
            // Their meeting point is the start of cycle
            while(temp != slow) {
                slow = slow->next;
                temp = temp->next;
            }

            // Return starting node of cycle
            return slow;
        }
    }
};