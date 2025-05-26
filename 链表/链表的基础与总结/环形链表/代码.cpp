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
    bool hasCycle(ListNode *head) {
        //数组为空返回false
        if (head == NULL) return false;
        ListNode* fast = head;//快指针
        ListNode* slow = head;//慢指针
        //遍历整个链表
        while (slow->next != NULL && fast->next != NULL &&fast->next->next != NULL)//注意节点为空的情况
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)   return true;//节点相等有环
        }
        return false;
    }
};