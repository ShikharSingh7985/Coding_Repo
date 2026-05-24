/**
 * Intuition:
 * To check whether a linked list is palindrome or not,
 * we compare the first half with the reversed second half.
 *
 * Steps:
 * 1. Find the middle of the linked list using slow and fast pointers.
 * 2. Reverse the second half of the linked list.
 * 3. Compare nodes from the first half and reversed second half one by one.
 * 4. If all values match, the linked list is palindrome.
 *
 * Example:
 * Original list:
 * 1 -> 2 -> 3 -> 2 -> 1
 *
 * First half:
 * 1 -> 2 -> 3
 *
 * Second half:
 * 2 -> 1
 *
 * Reverse second half:
 * 1 -> 2
 *
 * Compare:
 * 1 with 1
 * 2 with 2
 *
 * Since all matched, it is palindrome.
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

    // Function to reverse a linked list
    ListNode* reverseList(ListNode* head) {

        // prev will store the previous node
        ListNode* prev = NULL;

        // temp is used to traverse the list
        ListNode* temp = head;
        
        while(temp) {

            // Store next node before breaking the link
            ListNode* front = temp->next;

            // Reverse the current node's link
            temp->next = prev;

            // Move prev forward
            prev = temp;

            // Move temp forward
            temp = front;
        }

        // prev becomes the new head after reversing
        return prev; 
    }

    bool isPalindrome(ListNode* head) {

        // Empty list or single node list is always palindrome
        if(head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // Find the middle node
        // slow will stop at the end of first half
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the linked list
        ListNode* newnode = reverseList(slow->next);

        // first starts from beginning of list
        ListNode* first = head;

        // second starts from reversed second half
        ListNode* second = newnode;  

        // Compare first half and reversed second half
        while(second != NULL) {

            // If values are different, list is not palindrome
            if(first->val != second->val) return false;

            // Move both pointers forward
            first = first->next;
            second = second->next;
        } 

        // If all values matched, list is palindrome
        return true;
    }
};