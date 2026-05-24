/**
 * Intuition:
 * We use two pointers: fast and slow.
 * First, move fast pointer n steps ahead.
 * This creates a gap of n nodes between fast and slow.
 *
 * Then move both fast and slow together until fast reaches the last node.
 * At that time, slow will be just before the node that needs to be deleted.
 *
 * Finally, delete that node by changing slow->next.
 *
 * Special case:
 * If fast becomes NULL after moving n steps, it means the node to delete is head.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // If list is empty or has only one node,
        // removing nth node will make it NULL
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* fast = head;
        ListNode* slow = head;

        // Store n in another variable because we should not destroy original n
        int x = n;

        // Move fast pointer n steps ahead
        while(x != 0) {
            fast = fast->next;
            x--;
        }

        // If fast becomes NULL, it means we have to delete the head node
        if(fast == NULL) return head->next;

        // Move both pointers until fast reaches the last node
        // Then slow will be just before the node to be deleted
        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete nth node from end by skipping it
        slow->next = slow->next->next;

        // Return updated head
        return head;
    }
};