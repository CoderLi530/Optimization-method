//题目链接：https://leetcode.cn/problems/merge-two-sorted-lists/?envType=study-plan-v2&envId=top-100-liked

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
class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        //使用双指针指向两个链表，较小值尾插，遍历完一个链表时，将另个链表的剩余部分尾插
        //时间复杂度O(n + m) 空间复杂度O(1)
        ListNode* guard = new ListNode(0);
        ListNode* end = guard;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        while (cur1 && cur2)
        {
            //进行值比较，存放节点
            if (cur1->val < cur2->val)
            {
                end->next = cur1;
                cur1 = cur1->next;
            } 
            else
            {
                end->next = cur2;
                cur2 = cur2->next;
            }
            end = end->next;
        }
        //将另一个链表的剩余节点尾插
        if (cur1) end->next = cur1;
        if (cur2) end->next = cur2;
        return guard->next;

        // //使用递归
        // //时间复杂度O(n + m) 空间复杂度O(n + m)-->递归函数占用栈空间
        // //子问题：两个节点比较
        // //子问题如何解决：较小值的节点尾插
        // //递归出口：为空返回另一个链表
        // if (list1 == nullptr) return list2;
        // else if (list2 == nullptr) return list1;
        // else if (list1->val < list2->val)
        // {
        //     list1->next = mergeTwoLists(list1->next, list2);
        //     return list1;
        // }
        // else 
        // {
        //     list2->next = mergeTwoLists(list1, list2->next);
        //     return list2;
        // }
    }
};