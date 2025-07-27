//题目链接：https://leetcode.cn/problems/palindrome-linked-list/?envType=study-plan-v2&envId=top-100-liked

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
    ListNode* guard;
public:

    //判断是否为回文链表的递归函数
    bool isPalindromeRecur(ListNode* head)
    {
        if (head)
        {
            //终止条件：值不相等返回false
            if (!isPalindromeRecur(head->next)) return false;
            //比较的值不相等返回false
            if (head->val != guard->val) return false;
            //相等guard指向下个位置
            guard = guard->next;
        }
        return true;
    }

    //得到前半部分的尾节点
    ListNode* getFirstHalfEnd(ListNode* head)
    {
        //使用快慢指针，将slow指向中间节点
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    //对后半部分链表进行反转
    ListNode* secondHalfReverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        //不管奇数还是偶数，两个链表长度是相等的
        //如：1->2->3->2->1 前半部分1->2->3（没有修改2的指向） 后半部分1->2->3
        //1->2->2->1 前半部分1->2 后半部分1->2
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        // //1. 将链表中的值存到数组中，然后继续双指针比较
        // //空间复杂度O(n)，时间复杂度O(n)
        // vector<int> arr;
        // ListNode* cur = head;
        // while (cur)
        // {
        //     arr.push_back(cur->val);
        //     cur = cur->next;
        // }
        // //比较数组的值
        // int begin = 0, end = arr.size() - 1;
        // //注意判断条件begin < end，不加这个条件就会有越界访问的情况
        // while (begin < end && begin != end) 
        // {
        //     if (arr[begin] != arr[end]) return false;
        //     ++begin, --end;
        // }
        // return true;

        // //2. 通过递归的算法，让反向和正向迭代比较
        // //创建指针作为正向迭代开始，该指针指向head
        // //时间复杂度O(n) 空间复杂度O(n)-->递归在栈中放入了n个函数（n指链表的大小）
        // guard = head;
        // return isPalindromeRecur(head);

        //3. 在链表的开始位置和中间位置进行比较遍历
        //时间复杂度O(n) 空间复杂度O(1)
        //找到链表的前半部分的尾节点
        ListNode* firstHalfEnd = getFirstHalfEnd(head);
        //对链表后半部分进行翻转
        ListNode* secondHalfStart = secondHalfReverse(firstHalfEnd);
        ListNode* reverseStart = secondHalfStart;
        //进行比较，比较时不直接返回，还要将链表恢复原状
        bool ret = true;
        ListNode* firstHalfStart = head;
        while (firstHalfStart)
        {
            if (ret && firstHalfStart->val != secondHalfStart->val) 
            {
                ret = false;
                break;
            }
            firstHalfStart = firstHalfStart->next;
            secondHalfStart = secondHalfStart->next;
        }
        //将后半部分的链表反转回来
        secondHalfReverse(reverseStart);
        //返回结果
        return ret;
    }
};