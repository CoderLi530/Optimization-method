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
    int kthToLast(ListNode* head, int k) {
        //题目中保证k是有效的，所以当只有一个节点时就是答案
        if (head->next == NULL) return head->val;

        ListNode* fast = head;
        ListNode* slow = head;
        int i = k;

        //初始化fast的位置
        while (--i)//找到倒数第k个节点，fast要先走k - 1步
        {
            fast = fast->next;
        } 
        //遍历这个链表
        while (fast->next != NULL)//fast到达最后一个节点时，slow就是倒数第k个节点
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow->val;
    }
};