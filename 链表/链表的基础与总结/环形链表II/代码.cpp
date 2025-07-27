//题目链接：https://leetcode.cn/problems/linked-list-cycle-ii/?envType=study-plan-v2&envId=top-100-liked

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {
        //链表的开始位置到环的入口的距离 == 相遇点到环入口的距离（逆时针）
        //时间复杂度O(n) 空间复杂度O(1)
        //使用快慢指针找到相遇点
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        bool isRing = false;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) 
            {
                isRing = true;
                break;
            }
        }
        //判断是否有环
        if (!isRing || slow != fast) return nullptr;
        //从链表的开始位置和相遇点同时出发，相遇时就是入口
        ListNode* meet = slow;
        ListNode* begin = head;
        while (meet != begin)
        {
            meet = meet->next;
            begin = begin->next;
        }
        //返回环的入口
        return meet;

        // //2. 使用哈希表，遍历链表时在哈希表中查找，有环的话找到的位置是入口，没有环返回nullptr
        // //时间复杂度O(n) 空间复杂度O(n)
        // unordered_set<ListNode*> hash;
        // ListNode* cur = head;
        // while (cur)
        // {
        //     if (hash.count(cur))
        //     {
        //         return cur;
        //     }
        //     hash.insert(cur);
        //     cur = cur->next;
        // }
        // return nullptr;
    }
};