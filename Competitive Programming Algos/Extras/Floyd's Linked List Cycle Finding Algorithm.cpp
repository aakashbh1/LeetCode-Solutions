// Presence of cycle
public boolean hasCycle(ListNode head) {
    ListNode slow = head;
    ListNode fast = head;

    while(slow !=null && fast != null && fast.next != null){
        slow = slow.next;
        fast = fast.next.next;
        if(slow==fast){
            return true;
        }
    }

    return false;
}
// Assuming there is a cycle present and slow and fast are point to their meeting point
slow = head;
while(slow!=fast){
    slow = slow.next;
    fast = fast.next;
}

return slow; // the starting point of the cycle.
