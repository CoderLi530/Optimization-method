//题目链接：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/?envType=study-plan-v2&envId=top-100-liked

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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        // //1. 遍历链表，计算出链表的长度，然后找到对应位置删除节点
        // //时间复杂度O(n) 空间复杂度O(1)
        // if (head->next == nullptr) return nullptr;
        // ListNode* cur = head;
        // int count = 0;
        // //计算出链表的长度
        // while (cur)
        // {
        //     ++count;
        //     cur = cur->next;
        // }
        // //找到对应位置删除节点
        // ListNode* guard = new ListNode(0);
        // guard->next = head;
        // ListNode* prev = guard;
        // ListNode* del = head;
        // for (int i = 0; i < count - n; ++i)
        // {
        //     prev = del;
        //     del = del->next;
        // }
        // //头插的情况直接将下个节点覆盖前个节点 --> 直接使用哨兵节点就不用特殊处理删除头节点的情况了
        // // if (del == head)
        // // {
        // //     head = del->next;
        // //     return head;
        // // }
        // ListNode* next = del->next;
        // prev->next = next;
        // ListNode* ret = guard->next;
        // delete guard;
        // return ret;

        // //2. 使用栈，通过先进后出，弹出节点直到栈顶为倒数第n个节点
        // //但是要删除栈顶节点，还要找到其前驱节点，所以让栈顶元素为前驱节点可以很好操作了
        // //时间复杂度O(n) 空间复杂度O(n)
        // stack<ListNode*> st;
        // ListNode* guard = new ListNode(0);
        // guard->next = head;
        // ListNode* cur = guard;
        // while (cur)
        // {
        //     st.push(cur);
        //     cur = cur->next;
        // }
        // //弹出节点，栈顶元素为要删除节点的前驱节点
        // for (int i = 0; i < n; ++i)
        // {
        //     st.pop();
        // }
        // //栈顶节点的next就是要删除的节点
        // ListNode* del = st.top()->next;
        // st.top()->next = del->next;
        // ListNode* ret = guard->next;
        // delete guard;
        // return ret;

        //3. 使用先后指针，slow和fast指向head，fast先走n步，然后slow和fast同时出发，fast指向空时slow指向了倒数第n个节点
        //时间复杂度O(n)-->只需要遍历一遍链表 空间复杂度O(1)
        ListNode* guard = new ListNode(0);
        guard->next = head;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = guard; //要删除节点的前驱节点
        //fast先走n步
        for (int i = 0; i < n; ++i)
        {
            fast = fast->next;
        }
        //slow和fast同时出发
        while (fast)
        {
            fast = fast->next;
            prev = slow; //更新前驱节点
            slow = slow->next;
        }
        //slow指向了倒数第n个节点
        prev->next = slow->next;
        ListNode* ret = guard->next;
        delete guard;
        return ret;
    }
};