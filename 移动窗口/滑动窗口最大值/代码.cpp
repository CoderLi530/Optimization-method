//题目链接：https://leetcode.cn/problems/sliding-window-maximum/?envType=study-plan-v2&envId=top-100-liked

class Solution 
{
public:


    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        // //1. 将滑动窗口中的值进堆，建大堆
        // //超时 时间复杂度O(n*k*logk) 空间复杂度O(n)
        // vector<int> ret;
        // for (int left = 0; left < nums.size() - k + 1; ++left)
        // {
        //     int right = left + k - 1;
        //     priority_queue<int> pq;
        //     for (int i = left; i <= right; ++i)
        //     {
        //         pq.push(nums[i]);
        //     }
        //     ret.push_back(pq.top());
        // }
        // return ret;

        // //2. 保存堆的思路 -- 使用存储索引+过滤过期元素进行优化
        // //时间复杂度O(nlogn) 空间复杂度O(n)
        // priority_queue<pair<int, int>> pq;
        // vector<int> ret;
        // for (int i = 0; i < k; ++i) pq.push({nums[i], i});
        // ret.push_back(pq.top().first); //存储第一个最大值
        // for (int i = k; i < nums.size(); ++i)
        // {
        //     pq.push({nums[i], i});
        //     //进行过滤元素
        //     while (pq.top().second <= i - k)
        //     {
        //         pq.pop();
        //     }
        //     ret.push_back(pq.top().first);
        // }
        // return ret;

        //3. 使用双端队列deque
        //时间复杂度O(n) 空间复杂度O(k)
        vector<int> ret;
        deque<int> dq;
        for (int i = 0; i < nums.size(); ++i)
        {
            //不在滑动窗口的元素出队列
            if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
            //小于当前元素的出队列
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            //将当前元素的索引进队列
            dq.push_back(i);
            //在滑动窗口中 && 队列的初始位置
            if (dq.back() >= k - 1) ret.push_back(nums[dq.front()]);
        }
        return ret;

    }
};