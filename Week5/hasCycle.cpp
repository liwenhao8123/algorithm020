/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //方法一：哈希表

class Solution {
public:
    bool hasCycle(ListNode * head){
        unordered_set<ListNode *> seen;
        while (head != NULL){
            if (seen.count(head)){
                return true;
            }
            seen.insert(head);
            head = head->next;
        }
        return false;
    }
};

//方法二：快慢指针
class Solution {
public:
    bool hasCycle(ListNode * head){
        ListNode * fast = head, * slow = head;
        while (fast != NULL){
            if (fast->next == NULL){
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow){
                return true;
            }
        }
        return false;
    }
};
