[两数相加II]: https://leetcode.cn/problems/add-two-numbers-ii/

```c++
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* guard1 = NULL;//l1的哨兵位节点
        ListNode* guard2 = NULL;//l2的哨兵位节点
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        //进行翻转链表
        while (cur1 != NULL)//翻转链表l1
        {
            ListNode* next1 = cur1->next;
            cur1->next = guard1;
            guard1 = cur1;
            cur1 = next1;
        }
        while (cur2 != NULL)//翻转链表l2
        {
            ListNode* next2 = cur2->next;
            cur2->next = guard2;
            guard2 = cur2;
            cur2 = next2;
        }
        //进行两数相加。利用加法运算即可
        ListNode* tmp = new ListNode(0);//得到逆序链表，需反转链表得到正序链表
        ListNode* end = tmp;
        int t = 0;//进位数
        while (guard1 != NULL && guard2 != NULL)
        {
            t += guard1->val + guard2->val;
            end->next = new ListNode(t % 10);
            t /= 10;
            end = end->next;
            guard1 = guard1->next;
            guard2 = guard2->next;
        }
        //其中一个链表走完了，另一个链表没走完
        while (guard1 != NULL) 
        {
            t += guard1->val;
            end->next = new ListNode(t % 10);
            t /= 10;
            end = end->next;
            guard1 = guard1->next;
        }
        while (guard2 != NULL)
        {
            t += guard2->val;
            end->next = new ListNode(t % 10);
            t /= 10;
            end = end->next;
            guard2 = guard2->next;
        }
        //t等于1就说明还需要进位
        if (t == 1) end->next = new ListNode(1);
        //进行翻转链表得到正序链表
        ListNode* ret = NULL;
        ListNode* cur = tmp->next;
        while (cur != NULL)
        {
            ListNode* next = cur->next;
            cur->next = ret;
            ret = cur;
            cur = next;
        }
        return ret;
    }
};
```

