//Approach 1 
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head->next)
            return head;
        ListNode* dummy = new ListNode(0) ;
        
        dummy->next = head ; 
        ListNode *leftPart = dummy ;
		
        //we traverse to the node just before the node at left position
        for(int i=1;i<left;i++){
            leftPart=leftPart->next ; 
            
        }
       // We are saving the next nodes for future use
        ListNode* newHead = leftPart->next , *curr = newHead,*prev=NULL, *nextt;
        

        // swapping links, i.e reversing the later part of the list 
		
        for(int i=0;i<right-left+1;i++){
            nextt = curr->next ; 
            curr->next = prev ; 
            prev = curr ; 
            curr = nextt;
          
        }
       //connecting the relevant parts again to get the entire list
         
        leftPart->next = prev ; 
        newHead->next = nextt;
        
        return dummy->next;
    }
};

//Approach 2 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        for (int i = 0; i < left-1; i++) {
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        
        for (int i = 0; i < right-left; i++) {
            ListNode* next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        
        return dummy->next;
    }
};
