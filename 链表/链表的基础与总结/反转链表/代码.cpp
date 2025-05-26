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
    ListNode* reverseList(ListNode* head) {
        //空链表和只有一个节点的链表直接返回
        if (head == NULL || head->next == NULL) return head;

        //创建哨兵位节点
        ListNode* guard = NULL;
        ListNode* cur = head;
        //遍历链表，将每个节点头插到哨兵位中
        while (cur != NULL)
        {
            ListNode* next = cur->next;
            cur->next = guard;
            guard = cur;
            cur = next;
        }
        return guard;
    }
};