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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
         ListNode* current = head;
    while (current && current->next) {
        int val1 = current->val;
        int val2 = current->next->val;
        int greatestCommonDivisor = gcd(val1, val2);

        ListNode* newNode = new ListNode(greatestCommonDivisor);
        newNode->next = current->next;
        current->next = newNode;

        current = current->next->next;
    }
    return head;
    }
};
