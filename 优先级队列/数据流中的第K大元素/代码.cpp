//自己创建比较函数
class KthLargest 
{
public:
    struct cmp
    {
        bool operator() (int x, int y)
        {
            return x > y;
        }
    };
    priority_queue<int, vector<int>, cmp> pq;
    KthLargest(int k, vector<int>& nums) 
    {
        //取k个数据放到pq当中
        for (int i = 0; i < nums.size(); ++i)
        {
            //pq中元素等于k，进行比较更大值入队列
            if (pq.size() == k)
            {
                if (nums[i] > pq.top()) 
                {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
            //pq元素小于k存放元素
            else pq.push(nums[i]);
        }
        //pq元素不满k个，进行补足k个
        while (pq.size() != k) pq.push(INT_MIN);        
    }
    
    int add(int val) 
    {
        //进行寻找第K大的元素
        if (val > pq.top())
        {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */



//优化代码
 class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int _k;
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for (auto x : nums)
        {
            pq.push(x);
            if (pq.size() > _k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > _k) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */