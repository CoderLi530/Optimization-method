class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //只有一个石头
        if (stones.size() == 1) return stones[0];
        priority_queue<int> pq;//大根堆
        //石头进大根堆
        for (auto x : stones) pq.push(x);
        //取出石头进行粉碎操作
        while (pq.size() > 1)//只有一个石头或者没有石头就结束
        {
            //取出两个石头进行粉碎操作
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            if (s1 - s2) pq.push(s1 - s2);
        }
        //循环结束，返回结果
        return pq.size() > 0 ? pq.top() : 0;
    }
};