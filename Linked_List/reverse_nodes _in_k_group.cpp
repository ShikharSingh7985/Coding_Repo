/**
 * Intuition:
 *
 * We have to reverse nodes in groups of size k.
 *
 * Example:
 * 1 -> 2 -> 3 -> 4 -> 5
 * k = 2
 *
 * Groups:
 * (1 -> 2), (3 -> 4), (5)
 *
 * Reverse complete groups only:
 * 2 -> 1 -> 4 -> 3 -> 5
 *
 * Main idea:
 *
 * 1. Start from temp.
 * 2. Find the kth node from temp.
 * 3. If kth node does not exist, it means less than k nodes are left,
 *    so we do not reverse them.
 * 4. Store the next node after kth node.
 * 5. Break the group by doing kthnode->next = NULL.
 * 6. Reverse this k-sized group.
 * 7. Connect previous reversed group with current reversed group.
 * 8. Move temp to the next group.
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

    // Function to find kth node from current temp node
    ListNode* findkthnode(ListNode* temp, int k) {

        // Because temp itself is counted as the 1st node
        k--;

        // Move k-1 steps ahead
        while(temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }

        // Return kth node
        // If less than k nodes are present, this will return NULL
        return temp;
    }

    // Function to reverse a linked list
    ListNode* reverseLinkedList(ListNode* head) {

        // prev stores previous node
        ListNode* prev = NULL;

        // temp is used to traverse the list
        ListNode* temp = head;

        while(temp != NULL) {

            // Store next node before changing link
            ListNode* front = temp->next;

            // Reverse current node link
            temp->next = prev;

            // Move prev forward
            prev = temp;

            // Move temp forward
            temp = front;
        }

        // prev becomes new head after reversal
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        // If list is empty or k is 1, no reversal needed
        if(head == NULL || k == 1) return head;

        // temp points to the starting node of current group
        ListNode* temp = head;

        // prevnode stores the last node of previous reversed group
        ListNode* prevnode = NULL;

        // Traverse group by group
        while(temp != NULL) {

            // Find kth node from current group start
            ListNode* kthnode = findkthnode(temp, k);

            // If kth node does not exist,
            // less than k nodes are left, so do not reverse them
            if(kthnode == NULL) {

                // Connect previous reversed group with remaining nodes
                if(prevnode != NULL) {
                    prevnode->next = temp;
                }

                break;
            }

            // Store next group starting node
            ListNode* nextnode = kthnode->next;

            // Break current group from remaining list
            kthnode->next = NULL;

            // Reverse current k-sized group
            reverseLinkedList(temp);

            // If this is the first group,
            // kthnode becomes the new head after reversal
            if(temp == head) {
                head = kthnode;
            }

            // Otherwise connect previous group with current reversed group
            else {
                prevnode->next = kthnode;
            }

            // After reversal, temp becomes the last node of current group
            prevnode = temp;

            // Move temp to next group
            temp = nextnode;
        }

        // Return updated head
        return head;
    }
};