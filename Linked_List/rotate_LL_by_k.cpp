/**
 * Intuition:
 *
 * We have to rotate the linked list to the right by k places.
 *
 * Example:
 * 1 -> 2 -> 3 -> 4 -> 5
 * k = 2
 *
 * After rotating right by 2:
 * 4 -> 5 -> 1 -> 2 -> 3
 *
 * Main idea:
 *
 * 1. First find the length of the linked list.
 * 2. Since rotating by length gives the same list,
 *    we do k = k % len.
 * 3. Move fast pointer k steps ahead.
 * 4. Move slow and fast together until fast reaches the last node.
 * 5. Now slow will be just before the new head.
 * 6. Connect last node to old head.
 * 7. Make slow->next as new head.
 * 8. Break the link after slow.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
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
    ListNode* rotateRight(ListNode* head, int k) {

        // len stores the length of linked list
        int len = 0;

        // If list is empty or has only one node, no rotation needed
        if(head == NULL || head->next == NULL) return head;

        // temp is used to calculate length
        ListNode* temp = head;

        // Count total number of nodes
        while(temp != NULL) {
            temp = temp->next;
            len++;
        }

        // Remove unnecessary full rotations
        k = k % len;

        // fast and slow both start from head
        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast pointer k steps ahead
        for(int i = 0; i < k; i++) {
            fast = fast->next;
        }

        // Move both slow and fast together
        // When fast reaches last node,
        // slow will be just before the new head
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // Connect last node to old head
        fast->next = head;

        // New head will be slow->next
        head = slow->next;

        // Break the link to make slow the last node
        slow->next = NULL;

        // Return rotated list
        return head;
    }
};