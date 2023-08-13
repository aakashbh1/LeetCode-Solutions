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
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next;
    }
    
    
    
    
      ListNode* rev(ListNode* head){
        ListNode*current=head;
        ListNode*prev=NULL;
        ListNode*next=NULL;
        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        return prev;
    }
    
    
//     ListNode* addTwoLists(ListNode* first,ListNode* second)
//     {
//         int carry=0;
//         first=rev(first);
//         second=rev(second);
//         ListNode*dummy= new ListNode(0);
//         ListNode*start=dummy;
//         while(first!=NULL || second!=NULL || carry){
//             int sum=0;
//             if(first!=NULL){
//                 sum+=first->val;
//                 first=first->next;
//             }
//             if(second!=NULL){
//                 sum+=second->val;
//                 second=second->next;
//             }
//             sum+=carry;
//             ListNode* newNode= new ListNode(sum%10);
//             start->next=newNode;
//             start=start->next;
//             carry=sum/10;
//         }
//         return rev(dummy->next);
//     }
    
    
    ListNode* doubleIt(ListNode* head) {
        head=rev(head);
        ListNode* dummy= addTwoNumbers(head,head);
        dummy=rev(dummy);
        return dummy;
        
        // return addTwoLists(head,head);
    }
};
