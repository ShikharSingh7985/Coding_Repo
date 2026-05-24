/**
 * Intuition:
 * We have to group nodes by their position, not by their value.
 *
 * Odd-position nodes should come first:
 * 1st, 3rd, 5th, ...
 *
 * Even-position nodes should come after them:
 * 2nd, 4th, 6th, ...
 *
 * So we maintain two separate chains:
 * 1. Odd list using pointer to
 * 2. Even list using pointer te
 *
 * While traversing, we connect odd nodes together and even nodes together.
 * At the end, we attach the even list after the odd list.
 *
 * Example:
 * Original:
 * 1 -> 2 -> 3 -> 4 -> 5
 *
 * Odd-position list:
 * 1 -> 3 -> 5
 *
 * Even-position list:
 * 2 -> 4
 *
 * Final:
 * 1 -> 3 -> 5 -> 2 -> 4
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
    ListNode* oddEvenList(ListNode* head) {

        // If list is empty or has only one node, no change is needed
        if(head==NULL || head->next==NULL) return head;

        // odd points to the head of odd-position nodes
        ListNode* odd=head;

        // even points to the head of even-position nodes
        ListNode* even=head->next;

        // to is the tail pointer of odd list
        ListNode* to=odd;

        // te is the tail pointer of even list
        ListNode* te=even;

        // Rearrange links until even pointer or its next becomes NULL
        while(te!=NULL && to!=NULL && te->next!=NULL && to->next!=NULL){

            // Connect current odd tail to next odd-position node
            to->next=te->next;

            // Move odd tail forward
            to=te->next;

            // Connect current even tail to next even-position node
            te->next=to->next;

            // Move even tail forward
            te=to->next;
        }

        // If even tail is not NULL, end the even list properly
        if(te!=NULL) te->next=NULL;

        // Attach even-position list after odd-position list
        to->next=even;

        // Return head of rearranged list
        return odd;
        
    }
};