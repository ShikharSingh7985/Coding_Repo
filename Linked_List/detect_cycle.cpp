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
    bool hasCycle(ListNode *head) {

        // slow pointer moves one step at a time
        ListNode* slow = head;

        // fast pointer moves two steps at a time
        ListNode* fast = head;

        // continue until fast reaches NULL
        // if fast or fast->next becomes NULL, there is no cycle
        while (fast != NULL && fast->next != NULL) {

            // move slow pointer by one node
            slow = slow->next;

            // move fast pointer by two nodes
            fast = fast->next->next;

            // if slow and fast meet, cycle exists
            if (slow == fast) return true;
        }

        // if loop ends, fast reached NULL, so no cycle
        return false;
    }
};