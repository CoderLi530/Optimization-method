class MedianFinder {
    priority_queue<double> max_pq;
    priority_queue<double, vector<double>, greater<int>> min_pq;
public:
    MedianFinder() {
        //初始化
    }
    
    void addNum(int num) {
        //实现大小堆
        if (max_pq.size() == min_pq.size())
        {
            //先判断是否为空，再进行比较。
            if (max_pq.empty() || num <= max_pq.top()) max_pq.push(num);
            else 
            {
                min_pq.push(num);
                max_pq.push(min_pq.top());
                min_pq.pop();
            }
        }
        else
        {
            if (num <= max_pq.top())
            {
                max_pq.push(num);
                min_pq.push(max_pq.top());
                max_pq.pop();
            }
            else min_pq.push(num);
        }
    }
    
    double findMedian() {
        //返回中位数
        if (max_pq.size() == min_pq.size()) return (max_pq.top() + min_pq.top()) / 2;
        else return max_pq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */