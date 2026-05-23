// first method -> Use Hasing(map) store Nodes and timer 



/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        
        Node* slow=head;
        Node* fast=head;
        bool flag =false;
        int length=1;
        
        
        while(fast!=NULL && fast->next!=NULL){
            
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast) {
                flag=true;
                break;
            };
        }
        
        if(flag==false) return 0;
        else{
            fast=fast->next;
            while(slow!=fast){
            fast=fast->next;
            length++;
            }
        }
        return length;
        
    }
};