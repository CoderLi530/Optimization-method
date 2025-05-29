class Solution {
public:
    struct cmp
    {
        bool operator() (pair<string, int>& p1, pair<string, int>& p2)
        {
            //频次相同，按字典顺序排序（大根堆）
            if (p1.second == p2.second) return p1.first < p2.first;
            //频次不同，按频次多少排序（小根堆）
            else return p1.second > p2.second;  
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        //1. 创建哈希表，记录单词出现的频率
        unordered_map<string, int> hash;
        for (auto& s : words) hash[s]++;
        //2. 创建k个元素的堆，遍历哈希表，让元素进堆
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        for (auto& tmp : hash)
        {
            pq.push(tmp);
            if (pq.size() > k) pq.pop(); 
        }
        //3. 将堆中的数据存放到vector<string>中
        vector<string> ret(k);
        //倒放元素，就不用将ret逆序
        for (int i = k - 1; i >= 0; --i)
        {
            ret[i] = pq.top().first;
            cout << pq.top().first << endl;
            pq.pop();
        }
        return ret;
    }
};