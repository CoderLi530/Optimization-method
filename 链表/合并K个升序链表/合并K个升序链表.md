[合并K个升序链表]: https://leetcode.cn/problems/vvXgSW/submissions/629144299/



暴力解法

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == nullptr || l2 == nullptr) return l1 ? l1 : l2;
        ListNode* guard = new ListNode(0);
        ListNode* end = guard;
        ListNode* cur1 = l1, *cur2 = l2;
        while (cur1 && cur2)
        {
            if (cur1->val > cur2->val)
            {
                end->next = cur2;
                cur2 = cur2->next;
            }
            else
            {
                end->next = cur1;
                cur1 = cur1->next;
            }
            end = end->next;
        }
        //
        end->next = cur1 ? cur1 : cur2;
        return guard->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        //
        ListNode* ret = nullptr;
        for (int i = 0; i < lists.size(); ++i)
        {
            ret = mergeTwoLists(ret, lists[i]);
        }
        return ret;
    }
};
```



使用优先级队列

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
    struct cmp
    {
        bool operator() (ListNode* x, ListNode* y)
        {
            return x->val > y->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        //创建优先级队列
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        //输入k个数据
        for (auto l : lists)
        {
            if (l) pq.push(l);
        }
        //取出数据
        ListNode* guard = new ListNode(0);
        ListNode* end = guard;
        while (!pq.empty())
        {
            ListNode* tmp = pq.top();
            pq.pop();
            end->next = tmp;
            end = end->next;
            if (tmp->next) pq.push(tmp->next);
        }
        return guard->next;

    }
};
```



采用分治-递归

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        //链表为空就返回
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        //进行合并操作
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        ListNode* cur1 = list1, *cur2 = list2;
        while (cur1 && cur2)
        {
            if (cur1->val > cur2->val)
            {
                tail->next = cur2;
                cur2 = cur2->next;
            }
            else
            {
                tail->next = cur1;
                cur1 = cur1->next;
            }
            tail = tail->next;
        }
        tail->next = cur1 ? cur1 : cur2;
        
        //注意释放指针
        ListNode* ret = head->next;
        delete head;
        return ret;
    }
    ListNode* mergeRecurKLists(vector<ListNode*>& lists, int begin, int end)
    {
        //处理边界情况
        if (begin > end) return nullptr;
        if (begin == end) return lists[begin];

        //平分链表。注意范围取值
        int mid = (begin + end) / 2;
        ListNode* list1 = mergeRecurKLists(lists, begin, mid);
        ListNode* list2 = mergeRecurKLists(lists, mid + 1, end);

        //合并链表
        return mergeTwoLists(list1, list2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        return mergeRecurKLists(lists, 0, lists.size() - 1);
    }
};
```

