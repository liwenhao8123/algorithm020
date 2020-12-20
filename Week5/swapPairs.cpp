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

//方法一： 迭代法  时间复杂度O(n) n为链表的长度  空间复杂度O(1) 不需要再开辟空间
//采用扩展一个虚拟头结点的方法，这样会方便处理，尤其是边界条件，不然每次针对头结点（没有前一个指针指向头结点），还要单独处理。
/*
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummyHead;
        ListNode * tmp = &dummyHead;
        dummyHead.next = head;
        while(tmp->next != NULL && tmp->next->next != NULL){
            ListNode * node1 = tmp->next;
            ListNode * node2 = tmp->next->next;
            node1->next = node2->next;
            node2->next = node1;
            tmp->next = node2;
            tmp = node1;
        }
        return dummyHead.next;
    }
};
*/

//方法二：递归调用，符合重复子问题的应用条件  时间复杂度O(n)  空间复杂度O(n) n为递归调用中系统维护的栈深度
//取head指向原始链表的头，取newHead指向原始链表的第二个节点  完成一次交换后，newHead指向新链表的头节点，head指向新链表的第二个节点，最后向上层返回newHead
//结束条件head为NULL（无节点）或者head->next为NULL（只剩一个节点）

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //终止条件
        if (head == NULL || head->next == NULL){
            return head;
        }
        //本层处理
        ListNode * newHead = head->next; //定义newHead指向原链表第二个节点
        //调用下一层
        head->next = swapPairs(newHead->next);  //交换后head为新链表第二个节点，其next指向后面的链表
        //注意原链表第二个节点的next指向的是后面链表，所以要传递下去
        //回收处理   交换完成后，newHead指向新链表第一个节点，其next指向head（新链表的第二个节点）
        newHead->next = head;
        return newHead;
    }
};

