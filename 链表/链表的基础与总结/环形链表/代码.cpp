//题目链接：https://leetcode.cn/problems/linked-list-cycle/?envType=study-plan-v2&envId=top-100-liked

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
    bool hasCycle(ListNode *head) 
    {
        // //1. 快慢指针，fast比slow多走一步，如果有环一定会相遇
        // //时间复杂度O(n) 空间复杂度O(1)
        // if (head == nullptr || head->next == nullptr) return false;
        // ListNode* fast = head;
        // ListNode* slow = head;
        // while (fast->next && fast->next->next)
        // {
        //     fast = fast->next->next;
        //     slow = slow->next;
        //     //相遇返回true
        //     if (fast == slow) return true;
        // }
        // //链表中没有环，返回false
        // return false;

        //2. 哈希表，遍历链表时在哈希表中查找，找到了说明有环
        //时间复杂度O(n) 空间复杂度O(n)
        unordered_set<ListNode*> hash;
        ListNode* cur = head;
        while (cur)
        {
            //找到了直接返回
            if (hash.count(cur)) return true;
            //没找到，存入哈希表中
            hash.insert(cur);
            cur = cur->next;
        }
        //说明没有环，直接遍历空了
        return false;
    }
};