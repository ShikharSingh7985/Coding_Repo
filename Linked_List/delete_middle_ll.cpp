/**
 * Intuition:
 *
 * We need to delete the middle node of the linked list.
 *
 * To delete any node in a singly linked list, we need access to the node
 * just before it, because we have to change its next pointer.
 *
 * So instead of stopping slow pointer exactly at the middle node,
 * we stop slow pointer just before the middle node.
 *
 * We use two pointers:
 * slow moves 1 step
 * fast moves 2 steps
 *
 * When fast reaches near the end, slow will be just before the middle node.
 * Then we delete the middle node using:
 *
 * slow->next = slow->next->next;
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
       
        // If list is empty or has only one node,
        // deleting middle means list becomes empty
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        // slow will stop just before the middle node
        ListNode* slow = head;

        // fast moves two steps to help find the middle
        ListNode* fast = head;
        
        // Move fast by 2 steps and slow by 1 step
        // This condition is written so that slow stops before middle node
        while (fast != nullptr && 
               fast->next != nullptr && 
               fast->next->next != nullptr && 
               fast->next->next->next != nullptr) {
           
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete the middle node by skipping slow->next
        slow->next = slow->next->next;

        // Return updated head
        return head;
    }
};