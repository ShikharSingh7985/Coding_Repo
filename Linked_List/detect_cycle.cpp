/**
 * Intuition:
 *
 * To detect a cycle in a linked list, we use Floyd's Cycle Detection Algorithm.
 * It uses two pointers: slow and fast.
 *
 * slow moves 1 step at a time.
 * fast moves 2 steps at a time.
 *
 * If there is a cycle, fast will eventually meet slow inside the cycle.
 * If there is no cycle, fast will reach NULL.
 *
 * Example:
 * 1 -> 2 -> 3 -> 4 -> 5
 *           ^         |
 *           |_________|
 *
 * Here, slow and fast will eventually meet, so cycle exists.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
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
    bool hasCycle(ListNode *head) {

        // slow pointer moves one step at a time
        ListNode* slow = head;

        // fast pointer moves two steps at a time
        ListNode* fast = head;

        // Continue until fast reaches NULL
        // If fast or fast->next becomes NULL, there is no cycle
        while (fast != NULL && fast->next != NULL) {

            // Move slow pointer by one node
            slow = slow->next;

            // Move fast pointer by two nodes
            fast = fast->next->next;

            // If slow and fast meet, cycle exists
            if (slow == fast) return true;
        }

        // If loop ends, fast reached NULL, so no cycle
        return false;
    }
};