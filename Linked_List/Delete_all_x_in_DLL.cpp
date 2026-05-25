/**
 * Intuition:
 *
 * We need to delete all nodes whose value is equal to x
 * from a doubly linked list.
 *
 * Since deletion can also happen at the head node,
 * we use a dummy node before head.
 *
 * This makes deletion easier because every actual node
 * will have a previous node.
 *
 * For each node:
 * 1. If node value is x, store its next node.
 * 2. Change previous node's next pointer.
 * 3. If next node exists, change its prev pointer.
 * 4. Delete current node.
 * 5. Move to the stored next node.
 *
 * Finally, dummy->next becomes the new head.
 */

/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
*/

class Solution {
  public:

    Node* deleteAllOccurOfX(Node* head, int x) {
        
        // If list is empty, nothing to delete
        if(head == NULL) return NULL;
        
        // Create dummy node before head
        // This helps in deleting head nodes easily
        Node* dummy = new Node(-1);

        // Connect dummy with original head
        dummy->next = head;

        // Make dummy previous of head
        head->prev = dummy;
        
        // temp is used to traverse the list
        Node* temp = head;
        
        // Traverse the complete doubly linked list
        while(temp != NULL) {
            
            // If current node contains value x, delete it
            if(temp->data == x) {
                
                // Store next node before deleting current node
                Node* front = temp->next;
                
                // Link previous node to next node
                temp->prev->next = temp->next;
                
                // If next node exists, link it back to previous node
                if(temp->next != NULL) {
                    temp->next->prev = temp->prev;
                }
                
                // Delete current node from memory
                delete temp;

                // Move to next stored node
                temp = front;
            }
            
            // If current node value is not x, simply move ahead
            else {
                temp = temp->next;
            }
        }
        
        // New head is node after dummy
        head = dummy->next;
        
        // If list is not empty, head should not have previous node
        if(head != NULL) {
            head->prev = NULL;
        }
        
        // Delete dummy node from memory
        delete dummy;

        // Return updated head
        return head;
    }
};