 /**
 * Intuition:
 *
 * The linked list contains only 0s, 1s, and 2s.
 * We need to segregate them so that all 0s come first,
 * then all 1s, and finally all 2s.
 *
 * Instead of swapping data, we create three separate linked lists:
 * 1. List of 0s
 * 2. List of 1s
 * 3. List of 2s
 *
 * We use three dummy nodes to easily build these lists.
 * Then we connect:
 *
 * 0s list -> 1s list -> 2s list
 *
 * Finally, we return the head of the combined list.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
  public:
    Node* segregate(Node* head) {

        // Dummy node for list containing 0s
        Node* dummy1 = new Node(5);

        // Dummy node for list containing 1s
        Node* dummy2 = new Node(5);

        // Dummy node for list containing 2s
        Node* dummy3 = new Node(5);

        // a is tail pointer of 0s list
        Node* a = dummy1;

        // b is tail pointer of 1s list
        Node* b = dummy2;

        // c is tail pointer of 2s list
        Node* c = dummy3;

        // temp is used to traverse original list
        Node* temp = head;

        // Traverse the original linked list
        while (temp != nullptr) {

            // If current node contains 0,
            // attach it to 0s list
            if (temp->data == 0) {
                a->next = temp;
                a = a->next;
            }

            // If current node contains 1,
            // attach it to 1s list
            else if (temp->data == 1) {
                b->next = temp;
                b = b->next;
            }

            // If current node contains 2,
            // attach it to 2s list
            else {
                c->next = temp;
                c = c->next;
            }

            // Move to next node in original list
            temp = temp->next;
        }

        // End the 2s list properly
        c->next = nullptr;

        // Attach 2s list after 1s list
        b->next = dummy3->next;

        // Attach 1s list after 0s list if 1s list exists
        if (dummy2->next != nullptr) {
            a->next = dummy2->next;
        }

        // If 1s list does not exist,
        // attach 2s list directly after 0s list
        else {
            a->next = dummy3->next;
        }

        // New head is the first actual node after dummy1
        head = dummy1->next;

        // Delete dummy nodes because they were created using new
        delete dummy1;
        delete dummy2;
        delete dummy3;

        // Return updated sorted list
        return head;
    }
};