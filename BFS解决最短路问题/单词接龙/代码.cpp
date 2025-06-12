class Solution 
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> vis;//标记以存在的字符
        unordered_set<string> hash(wordList.begin(), wordList.end());//寻找是否出现
        queue<string> q;
        q.push(beginWord);
        vis.insert(beginWord);//标记单词已出现
        int ret = 1;//返回结果，开始单词结果+1
        while (!q.empty())
        {
            ++ret;//开始单词算一个
            int n = q.size();
            while (n--)//开始循环层数
            {
                //首个单词出队列，变化单词依次按照条件进队列
                string s = q.front();
                q.pop();                
                for (int i = 0; i < beginWord.size(); ++i)
                {
                    //设置一个临时变量来修改s
                    string tmp = s;
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        tmp[i] = c;
                        //不等于endWord进入队列，进入队列条件：vis未标记，hash中可以找到
                        if (!vis.count(tmp) && hash.count(tmp))
                        {
                            //此时单词等于endWord，直接返回结果
                            if (tmp == endWord) return ret;
                            q.push(tmp);
                            vis.insert(tmp);
                        }
                    }
                }
            }
        }
        //循环结束没有返回结果，说明不存在转换序列
        return 0;
    }
};