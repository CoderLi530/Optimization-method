//错误代码
//错误：使用unordered_map存放pair，需要自己实现unordered_map存放pair
class Solution 
{
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
public:
    int cutOffTree(vector<vector<int>>& forest) 
    {
        unordered_map<int, pair<int, int>> hash;//存放树的值和下标
        vector<int> v;//排序数组
        int m = forest.size(), n = forest[0].size();//几排几列
        int ret = 0;//返回结果
        queue<pair<int, int>> q;//下标进入队列
        q.push({0, 0});
        hash.insert(forest[0][0], {0, 0});
        v.push_back(forest[0][0]);
        forest[0][0] = 0;//对森林进行修改
        while (!q.empty())
        {
            int i = q.size();
            while (i--)         
            {
                auto [x, y] = q.front();
                q.pop();
                //找四个方向的树，放进队列、哈希和数组中
                for (int k = 0; k < 4; ++k)
                {
                    int a = x + dx[i], b = y + dy[i];
                    if (a >= 0 && a < m && b >= 0 && b < n && forest[a][b] >= 1)
                    {
                        q.push({a, b});
                        hash.insert(forest[a][b], {a, b});
                        v.push_back(forest[a][b]);
                        forest[a][b] = 0;
                    } 
                }
            }
        }
        //对数组进行排序
        sort(v.begin(), v.end());
        //计算步数
        for (int i = 1; i < v.size(); ++i)
        {
            int tmp1 = v[i], tmp2 = v[i - 1];
            ret += abs(hash[tmp1].first - hash[tmp2].first) + abs(hash[tmp1].second - hash[tmp2].second);
        }
        return ret;
    }
};


//使用lambda表达式对pair进行排序
class Solution 
{
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
public:
    //层序遍历
    int bfs(vector<vector<int>>& f, int bx, int by, int ex, int ey)
    {
        //初始位置和最终位置相同返回0
        if (bx == ex && by == ey) return 0;
        queue<pair<int, int>> q;
        bool vis[51][51] = {false};
        q.push({bx, by});
        vis[bx][by] = true;
        int step = 0;//步数
        while (!q.empty())
        {
            ++step;
            int n = q.size();
            while (n--)
            {
                auto [a, b] = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i)
                {
                    int x = a + dx[i], y = b + dy[i];
                    //f[x][y]找到指定位置的过程中数字大于0就可以走
                    if (x >= 0 && x < f.size() && y >= 0 && y < f[0].size() && f[x][y] && !vis[x][y])
                    {
                        if (x == ex && y == ey) return step;
                        q.push({x, y});
                        vis[x][y] = true;
                    }
                }
            }
        }
        //没有找到指定的树
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) 
    {
        int m = forest.size(), n = forest[0].size();
        vector<pair<int, int>> hash;
        //统计所有的树
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (forest[i][j] > 1) hash.push_back({i, j});
        
        //进行排序（使用lambda表达式）
        sort(hash.begin(), hash.end(), [&](const pair<int, int>& p1, const pair<int, int>& p2){
            return forest[p1.first][p1.second] < forest[p2.first][p2.second];
        });

        //计算步数
        int bx = 0, by = 0;
        int ret = 0;
        for (auto& [a, b] : hash)
        {
            int step = bfs(forest, bx, by, a, b);
            if (step == -1) return -1;//没有走到指定的树，返回-1
            ret += step;
            //位置覆盖
            bx = a, by = b;
        }
        //返回结果
        return ret;
    }
};