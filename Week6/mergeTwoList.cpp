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
/*
//方法一： 递归，每次取value较小的那个与其他元素merge的结果组成当前层的处理
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr){
            return l2;
        }else if (l2 == nullptr){
            return l1;
        }else if (l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
*/

//迭代法：  新增一个头结点（哨兵节点、哑结点）
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * preHead = new ListNode(-1);
        ListNode * prev = preHead;
        
        while (l1 != nullptr && l2 != nullptr){
            if (l1->val < l2->val){
                prev->next = l1;
                l1 = l1->next;
            }else{
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        prev->next = l1 == nullptr ? l2 : l1;
        return preHead->next;
    }
};