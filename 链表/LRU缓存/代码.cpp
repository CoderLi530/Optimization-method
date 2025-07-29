//题目链接：https://leetcode.cn/problems/lru-cache/?envType=study-plan-v2&envId=top-100-liked

struct DLinkNode
{
    int key, val;
    DLinkNode* prev;
    DLinkNode* next;
    DLinkNode(): key(0), val(0), prev(nullptr), next(nullptr) {}
    DLinkNode(int _key, int _val): key(_key), val(_val), prev(nullptr), next(nullptr) {}
};

class LRUCache 
{
    unordered_map<int, DLinkNode*> cache;
    DLinkNode* guard;
    DLinkNode* tail;
    int size;
    int capacity;
public:

    //将节点移到头部
    void moveToHead(DLinkNode* node)
    {
        //该节点的前驱节点和后继节点进行连接
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        addToHead(node);
    }

    //将节点添加到头部
    void addToHead(DLinkNode* node)
    {
        //哨兵位节点 该节点 哨兵位节点next
        node->next = guard->next;
        guard->next->prev = node;
        guard->next = node;
        node->prev = guard;
    }

    //删除尾节点
    DLinkNode* removeTail()
    {
        DLinkNode* del = tail->prev;
        del->prev->next = del->next;
        del->next->prev = del->prev;
        return del;
    }

    LRUCache(int _capacity) 
    : capacity(_capacity), size(0)
    {
        guard = new DLinkNode();
        tail = new DLinkNode();
        guard->next = tail;
        tail->prev = guard;
    }
    
    int get(int key) 
    {
        if (cache.count(key))
        {
            DLinkNode* ret = cache[key];
            moveToHead(cache[key]);
            return ret->val;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if (cache.count(key))
        {
            cache[key]->val = value;
            moveToHead(cache[key]);
        }
        else
        {
            DLinkNode* node = new DLinkNode(key, value);
            addToHead(node);
            cache.insert({key, node});
            ++size;
            if (size > capacity)
            {
                DLinkNode* del = removeTail();
                cache.erase(del->key);
                delete del;
                --size;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */