//题目链接：https://leetcode.cn/problems/copy-list-with-random-pointer/?envType=study-plan-v2&envId=top-100-liked

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution 
{
public:
    Node* copyRandomList(Node* head) 
    {
        // //1. 哈希表 遍历链表创建新链表，并使用hash存放原节点和新节点的映射关系，方便random的复制
        // //时间复杂度O(n) 空间复杂度O(n)
        // if (head == nullptr) return nullptr;
        // unordered_map<Node*, Node*> hash;
        // Node* cur = head;
        // //构建哈希表的映射关系
        // while (cur)
        // {
        //     Node* tmp = new Node(cur->val);
        //     hash.insert({cur, tmp});
        //     cur = cur->next;
        // }
        // //对next和random的复制
        // Node* begin = head;
        // while (begin)
        // {
        //     hash[begin]->next = hash[begin->next];
        //     hash[begin]->random = hash[begin->random];
        //     begin = begin->next;
        // }
        // return hash[head];

        //迭代，插入节点，拆分节点
        //时间复杂度O(n) 空间复杂度O(1)
        if (head == nullptr) return nullptr;
        Node* begin = head;
        //对每个节点进行拷贝一份到该节点的后面
        while (begin)
        {
            Node* tmp = new Node(begin->val);
            tmp->next = begin->next;
            begin->next = tmp;
            begin = begin->next->next;
        }
        //对拷贝后的节点进行random拷贝
        Node* cur = head;
        while (cur)
        {
            Node* copyNode = cur->next;
            if (cur->random) copyNode->random = cur->random->next;
            cur = cur->next->next;
        }
        //对链表拆分成原链表和新链表
        Node* node = head;
        Node* newHead = head->next;
        while (node)
        {
            Node* copyNode = node->next;
            node->next = copyNode->next;
            if (copyNode->next) copyNode->next = copyNode->next->next;
            node = node->next;
        } 
        return newHead;
    }
};