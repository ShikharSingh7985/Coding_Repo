/*
Intuition:

We are given k sorted linked lists.
We need to merge all of them into one sorted linked list.

Since every list is already sorted, the smallest available node
among all list heads should come first in the final list.

Main idea:

Use a min heap / priority queue.

The priority queue will always store the smallest current node
from each list.

Steps:

1. Push the head node of every non-empty list into the min heap.
2. Take the smallest node from the heap.
3. Add it to the final merged list.
4. If that node has a next node, push that next node into the heap.
5. Repeat until heap becomes empty.

Why min heap?

Because at every step, we need the smallest node among k lists.
Min heap gives that in O(log k).

Time Complexity: O(N log k)
where N = total number of nodes in all lists
and k = number of linked lists.

Space Complexity: O(k)
because heap stores at most k nodes at a time.
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

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Lambda function for min heap
        // It returns true when node1 value is greater than node2 value
        // So smaller value gets higher priority
        auto lambda = [](ListNode* node1, ListNode* node2) {
            return node1->val > node2->val;
        };

        // Min heap storing ListNode pointers
        priority_queue<ListNode*, vector<ListNode*>, decltype(lambda)> pq(lambda); 

        // Push head of every non-empty linked list into heap
        for(ListNode* node : lists) {
            if(node != NULL) {
                pq.push(node);
            }
        }

        // If all lists are empty, return NULL
        if(pq.empty()) {
            return NULL;
        }

        // Smallest node becomes head of final merged list
        ListNode* head = pq.top();
        pq.pop();

        // If head has next node, push it into heap
        if(head->next != NULL) {
            pq.push(head->next);
        }

        // tail is used to build final merged list
        ListNode* tail = head;

        // Continue until heap becomes empty
        while(!pq.empty()) {

            // Get smallest available node
            ListNode* curr = pq.top();
            pq.pop();

            // Attach current smallest node to final list
            tail->next = curr;

            // Move tail forward
            tail = tail->next;

            // If current node has next node,
            // push next node into heap
            if(curr->next != NULL) {
                pq.push(curr->next);
            }
        }

        // Return head of merged sorted list
        return head;
    }
};