/**
 * Intuition:
 *
 * Two linked lists may have different lengths.
 * If they intersect, the common part from the intersection point
 * to the end will be the same for both lists.
 *
 * So first we calculate the length of both lists.
 * Then we move the pointer of the longer list ahead by the length difference.
 *
 * After that, both pointers will have the same number of nodes left.
 * Now move both one step at a time.
 *
 * The first node where both pointers become equal is the intersection node.
 * If they never become equal, there is no intersection.
 *
 * Time Complexity: O(n + m)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // temp is used to traverse list A
        ListNode* temp = headA;

        // t is used to traverse list B
        ListNode* t = headB;

        // len1 stores length of list A
        int len1 = 0;

        // len2 stores length of list B
        int len2 = 0;

        // Calculate length of list A
        while(temp != NULL) {
            len1++;
            temp = temp->next;
        }

        // Calculate length of list B
        while(t != NULL) {
            len2++;
            t = t->next;
        }

        // Reset temp and t to the heads of both lists
        temp = headA;
        t = headB;

        // l stores the difference between the two lengths
        int l = 0;

        // If list A is longer, move temp ahead by length difference
        if(len1 > len2) {
            l = len1 - len2;

            for(int i = 0; i < l; i++) {
                temp = temp->next;
            }
        }

        // If list B is longer, move t ahead by length difference
        else if(len2 > len1) {
            l = len2 - len1;

            for(int i = 0; i < l; i++) {
                t = t->next;
            }
        }

        // Now both lists have equal remaining length
        // Move both pointers together
        while(temp != NULL && t != NULL) {

            // If both pointers point to same node,
            // this is the intersection point
            if(temp == t) return temp;

            temp = temp->next;
            t = t->next;
        }

        // If no common node is found, return NULL
        return NULL; 
    }
};