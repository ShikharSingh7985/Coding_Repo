/*
Intuition:

We need to create a deep copy of a linked list where each node has:
1. next pointer
2. random pointer

The main challenge is copying the random pointer correctly.

Normally, we can use a map:
original node -> copied node

But here we can do it without extra map space using interleaving.

Steps:

Step 1:
Create copied nodes and insert them just after original nodes.

Original:
A -> B -> C

After inserting copy nodes:
A -> A' -> B -> B' -> C -> C'

Step 2:
Set random pointers of copied nodes.

If original node A has random pointer to C,
then copied node A' should point to C'.

Since C' is just after C, we can write:
A'->random = A->random->next

Step 3:
Separate the original list and copied list.

Original list becomes:
A -> B -> C

Copied list becomes:
A' -> B' -> C'

Time Complexity: O(n)
Space Complexity: O(1)
*/

/*
 // Definition for a Node.
 class Node {
 public:
     int val;
     Node* next;
     Node* random;
     
     Node(int _val) {
         val = _val;
         next = NULL;
         random = NULL;
     }
 };
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        // If list is empty, return NULL
        if(head == NULL) return NULL;

        /*
        Step 1:
        Create copy nodes and insert them after original nodes.

        Original:
        A -> B -> C

        After this step:
        A -> A' -> B -> B' -> C -> C'
        */

        // temp is used to traverse original list
        Node* temp = head;

        while(temp != NULL) {

            // Create a copy node with same value as current original node
            Node* copyNode = new Node(temp->val);

            // Copy node should point to original node's next
            copyNode->next = temp->next;

            // Original node should point to its copy node
            temp->next = copyNode;

            // Move temp to next original node
            temp = temp->next->next;
        }

        /*
        Step 2:
        Set random pointers of copied nodes.

        For original node temp:
        copied node is temp->next

        If temp->random points to some original node,
        then temp->random->next is its copied node.
        */

        // Start again from head
        temp = head;

        while(temp != NULL) {

            // copyNode is the copied node of current original node
            Node* copyNode = temp->next;

            // If original node has random pointer
            if(temp->random != NULL) {

                // copied node random should point to copied version
                // of temp->random
                copyNode->random = temp->random->next;
            }

            // If original node random is NULL
            else {

                // copied node random should also be NULL
                copyNode->random = NULL;
            }

            // Move to next original node
            temp = temp->next->next;
        }

        /*
        Step 3:
        Separate original list and copied list.

        Current list:
        A -> A' -> B -> B' -> C -> C'

        After separation:
        Original: A -> B -> C
        Copy:     A' -> B' -> C'
        */

        // Dummy node to create copied list easily
        Node* dummy = new Node(-1);

        // res is tail pointer of copied list
        Node* res = dummy;

        // Start again from head
        temp = head;

        while(temp != NULL) {

            // Attach copied node to copied list
            res->next = temp->next;

            // Move copied list tail forward
            res = res->next;

            // Restore original list connection
            temp->next = temp->next->next;

            // Move temp to next original node
            temp = temp->next;
        }

        // Return head of copied list
        return dummy->next;
    }
};