class Solution 
{
public:
    string alienOrder(vector<string>& words) 
    {
        if (words.size() == 1) return words[0];
        //1. 建图存放数据
        unordered_map<char, unordered_set<char>> edges; //邻接表
        unordered_map<char, int> in; //入度值表，不初始化会导致入度值不正确
        for (auto& s : words)//入度值表进行初始化
        {
            for (char& c : s)
            {
                in[c] = 0;
            }
        }
        for (int i = 0; i < words.size() - 1; ++i)
        {
            for (int j = i + 1; j < words.size(); ++j)
            {
                //字符串比较
                int k = 0;
                while (k < words[i].size() && k < words[j].size())
                {
                    char a = words[i][k], b = words[j][k];
                    if (a != b) //字母不相等，前面的字母进入邻接表
                    {
                        //如果已经存在a->b，就不用执行该操作
                        if (edges[a].count(b)) break;
                        else 
                        {
                            edges[a].insert(b);
                            in[b]++;
                            break;
                        }
                    }
                    //字母相等，继续往后比较
                    else ++k;
                }
                //"abc" "ab" 这种情况不合法，直接返回""
                if (k == words[j].size() && k < words[i].size()) return "";
            }
        }
        //2. 拓扑排序
        queue<char> q; //队列
        string ret; //返回结果
        //入度值为0的数据进入队列
        for (auto& [c, i] : in)
        {
            if (i == 0) q.push(c); 
        }
        //bfs
        while (!q.empty())
        {
            char ch = q.front(); q.pop();
            ret += ch;
            for (auto& s : edges[ch])
            {
                in[s]--;
                if (in[s] == 0) q.push(s);
            }
        }
        //有环返回""，无环返回ret
        for (auto& [c, i] : in)
        {
            if (i) return "";
        }
        return ret;
    }
};