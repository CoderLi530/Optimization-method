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
    ListNode *detectCycle(ListNode *head) {
        //没有节点
        if (head == NULL) return NULL;

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* begin = head;
        while (slow->next != NULL && fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            //判断链表是否有环
            if (slow == fast)
            {
                //有环找到入口。两个指针分别从起点和相遇点同时走，在入口会相遇。
                while (begin != slow)
                {
                    begin = begin->next;
                    slow = slow->next;
                }
                return begin;
            } 
        }
        return NULL;
    }
};