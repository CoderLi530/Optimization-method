//题目链接：https://leetcode.cn/problems/sort-list/submissions/647942668/?envType=study-plan-v2&envId=top-100-liked

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
    //仿函数
    struct Compare
    {
        bool operator()(const ListNode* l1, const ListNode* l2)
        {
            //返回true，说明l1要排在l2前面
            return l1->val > l2->val;
        }
    };

    //找到中间节点
    ListNode* findMidNode(ListNode* node)
    {
        ListNode* slow = node;
        ListNode* fast = node->next;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    // //归并两个链表（自顶向下版本）
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    // {
    //     ListNode* guard = new ListNode(0);
    //     ListNode* end = guard;
    //     ListNode* cur1 = l1;
    //     ListNode* cur2 = l2;
    //     while (cur1 && cur2)
    //     {
            
    //         if (cur1->val < cur2->val)
    //         {
    //             end->next = cur1;
    //             end = end->next;
    //             cur1 = cur1->next;
    //         }
    //         else
    //         {
    //             end->next = cur2;
    //             end = end->next;
    //             cur2 = cur2->next;
    //         }
    //     }
    //     //将剩余链表链接后面
    //     if (cur1)
    //     {
    //         end->next = cur1;
    //     } 
    //     if (cur2) 
    //     {
    //         end->next = cur2;
    //     }
    //     ListNode* ret = guard->next;
    //     delete guard;
    //     return ret;
    // }

    //归并排序（自底向上版本）
    pair<ListNode*, ListNode*> mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* guard = new ListNode(0);
        ListNode* end = guard;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        while (cur1 && cur2)
        {
            
            if (cur1->val < cur2->val)
            {
                end->next = cur1;
                end = end->next;
                cur1 = cur1->next;
            }
            else
            {
                end->next = cur2;
                end = end->next;
                cur2 = cur2->next;
            }
        }
        //将剩余链表链接后面
        if (cur1)
        {
            end->next = cur1;
        } 
        if (cur2) 
        {
            end->next = cur2;
        }
        while (end->next) end = end->next;
        ListNode* ret = guard->next;
        delete guard;
        return {ret, end};
    }

    //分割链表
    ListNode* splitList(ListNode* node, int n)
    {
        if (node == nullptr) return node; 
        ListNode* cur = node;
        for (int i = 1; i < n; ++i)
        {
            if (cur->next) cur = cur->next;
        }
        ListNode* ret = cur->next;
        cur->next = nullptr; //断开连接
        return ret;
    }

public:
    ListNode* sortList(ListNode* head) 
    {
        // //1. 升序建大堆 -- 堆顶元素和最后一个元素交换，效率高
        // //时间复杂度O(nlogn) 空间复杂度O(n)
        // priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        // ListNode* cur = head;
        // //进堆
        // while (cur)
        // {
        //     pq.push(cur);
        //     cur = cur->next;
        // }
        // //进行修改节点指向
        // ListNode* guard = new ListNode(0);
        // ListNode* end = guard;
        // while (!pq.empty())
        // {
        //     ListNode* tmp = pq.top();
        //     ListNode* node = new ListNode(tmp->val);
        //     end->next = node;
        //     end = end->next;
        //     pq.pop(); 
        // }
        // ListNode* ret = guard->next;
        // delete guard;
        // return ret;


        // //2. 归并排序（递归版本--自顶向下）
        // //时间复杂度O(nlogn) 空间复杂度O(logn)
        // //(1. 找到中间位置进行切分为两个链表
        // //(2. 进行递归排序
        // //(3. 进行合并
        // if (head == nullptr || head->next == nullptr) return head;

        // //找到中间节点
        // ListNode* mid = findMidNode(head);
        // ListNode* right = mid->next;
        // mid->next = nullptr;

        // //进行左右部分的递归排序
        // ListNode* leftStart = sortList(head);
        // ListNode* rightStart = sortList(right);

        // //返回已排序好的链表
        // return mergeTwoLists(leftStart, rightStart);



        //3. 归并排序（非递归版本--自底向上）
        //时间复杂度O(nlogn) 空间复杂度O(1)
        //1对1链表合并，2对2链表合并......
        if (head == nullptr || head->next == nullptr) return head; 
        //求出链表的长度
        int n = 0;
        ListNode* tmp = head;
        while (tmp)
        {
            ++n;
            tmp = tmp->next;
        }
        ListNode* guard = new ListNode(0, head);
        
        //将链表分成子链表进行合并
        for (int i = 1; i < n; i *= 2)
        {
            ListNode* prev = guard;
            ListNode* begin = guard->next;
            while (begin)
            {
                ListNode* head1 = begin;
                ListNode* head2 = splitList(head1, i);
                begin = splitList(head2, i);
            
                //进行合并排序
                auto [start, tail]  = mergeTwoLists(head1, head2);
                //更新节点的位置
                prev->next = start;
                tail->next = begin;
                prev = tail; //更新虚拟节点
            }       
            
        }
        ListNode* ret = guard->next;
        delete guard;
        return ret;
    }
};