class Solution
{
    public:
    struct Node* reverse(struct Node* head){
        Node* curr=head;
        Node* prev=NULL,*next=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void rearrange(struct Node *odd)
    {
       Node * e_head=odd->next;
       Node* start= odd;
       Node* end=odd->next;
       while(end && end->next){
           start->next=start->next->next;
           start=start->next;
           end->next=start->next;
           end=end->next;
           
       }
        e_head=reverse(e_head);
        start->next=e_head;
        
        
    }
};
