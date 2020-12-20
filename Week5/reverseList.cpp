class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode * cur = NULL, * pre = head;
        while (pre != NULL){
            ListNode * tmp = pre->next;
            pre->next = cur;
            cur = pre;
            pre = tmp;
        }
        return cur;
    }
}