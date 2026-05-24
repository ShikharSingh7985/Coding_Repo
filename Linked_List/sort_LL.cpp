/**
 * Intuition:
 *
 * We are sorting a linked list using Merge Sort.
 *
 * Merge Sort idea:
 * 1. Divide the linked list into two halves.
 * 2. Recursively sort both halves.
 * 3. Merge the two sorted halves.
 *
 * Why Merge Sort for linked list?
 * In linked list, finding middle using slow-fast pointer is easy.
 * Also merging two sorted linked lists can be done in O(1) extra space
 * by changing links.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(log n) due to recursion stack
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

    // Function to merge two sorted linked lists
    ListNode* merge(ListNode* a, ListNode* b) {

        // Dummy node to simplify merging
        ListNode* c = new ListNode(100);

        // temp is used to build the final merged list
        ListNode* temp = c;

        // Compare nodes of both lists one by one
        while(a != NULL && b != NULL) {

            // If value of list a is smaller or equal,
            // attach node a to merged list
            if(a->val <= b->val) {
                temp->next = a;
                a = a->next;
                temp = temp->next;
            }

            // Otherwise attach node b to merged list
            else {
                temp->next = b;
                b = b->next;
                temp = temp->next;
            }
        }

        // If list a is finished, attach remaining list b
        if(a == NULL) temp->next = b;

        // If list b is finished, attach remaining list a
        else temp->next = a;

        // c is dummy node, so actual head is c->next
        return c->next;
    }

    ListNode* sortList(ListNode* head) {

        // Base case:
        // Empty list or single node list is already sorted
        if(head == NULL || head->next == NULL) return head;

        // slow will help us find middle of linked list
        ListNode* slow = head;

        // t is fast pointer, moves two steps
        ListNode* t = head;

        // Move slow by 1 step and t by 2 steps
        // When t reaches near end, slow will be at middle
        while((t->next != NULL) && (t->next->next != NULL)) {
            slow = slow->next;
            t = t->next->next;
        }

        // First half starts from head
        ListNode* a = head;

        // Second half starts after slow
        ListNode* b = slow->next;

        // Break the list into two separate halves
        slow->next = NULL;

        // Recursively sort first half
        a = sortList(a);

        // Recursively sort second half
        b = sortList(b);

        // Merge both sorted halves
        ListNode* c = merge(a, b);

        // Return sorted list
        return c;
    }
};