class Solution 
{
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) 
    {
        unordered_set<string> vis;//标记搜索过的状态
        unordered_set<string> hash(bank.begin(), bank.end());//在bank寻找基因序列
        queue<string> q;//进入字符串的队列
        string change = "ACGT";//改变的序列
        int ret = 0;//返回结果
        q.push(startGene);
        vis.insert(startGene);
        while (!q.empty())
        {
            //一层一层循环
            int n = q.size();
            while (n--)
            {
                string tmp = q.front();
                q.pop();
                //修改序列
                for (int i = 0; i < 8; ++i)
                {
                    string s = tmp;
                    for (int j = 0; j < 4; ++j)
                    {
                        s[i] = change[j];
                        //是否进入队列的条件：bank中存在、状态未标记
                        if (hash.count(s) && !vis.count(s))
                        {
                            //序列和endGene相同返回结果
                            if (s == endGene) return ++ret;
                            q.push(s);
                            vis.insert(s);                            
                        }
                    }
                }
            }
            ++ret;
        }
        //没有返回结果说明没有找到
        return -1;
    }
};