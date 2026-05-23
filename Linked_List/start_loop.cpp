// 1st method - use map to detect cycle and then return the first node which was found in the map

//2nd method is using fast and slow pointers 
        //1st detect the cycle 
        //then keep slow at head and go with fast one by one 
        //the place where they collide is starting of ll





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
ListNode* detectCycle(ListNode *head) {
ListNode* slow = head;
ListNode* fast = head;
bool flag = false; // no cycle
while(fast != NULL && fast->next != NULL) {
slow = slow->next;
fast = fast->next->next;
if(slow == fast){
flag = true;
break;

}

}

if(flag==false) return NULL;
else{
    ListNode* temp=head;
    while(temp!=slow){
        slow=slow->next;
        temp=temp->next;
    }
    return slow;
}



        
    }
};