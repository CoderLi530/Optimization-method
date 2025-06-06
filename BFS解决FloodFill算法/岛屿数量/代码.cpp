//在原数组上进行修改
class Solution 
{
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
public:
    //使用双循环时间会超时:没有第一时间修改为'0'，会在队列中进入重复元素，时间就会超时！！！
    //在原始数组上进行修改
    int numIslands(vector<vector<char>>& grid) 
    {
        int ret = 0;//返回的结果
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();//数组的几排几列
        //进行层序遍历
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                //遍历元素进入队列，进行计算四个方向的陆地
                if (grid[i][j] == '1')//说明找到了一个（一块）陆地，计数加1；
                {
                    ++ret;
                    q.push({i, j});
                    grid[i][j] = '0';
                    //计算四个方向的陆地
                    while (!q.empty())
                    {
                        //出队列，修改陆地为水，找四个方向的陆地
                        auto [x, y] = q.front();
                        q.pop();
                        //四个方向注意边界问题
                        for (int dir = 0; dir < 4; ++dir)
                        {
                            int a = dx[dir] + x, b = dy[dir] + y;
                            if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b] == '1')
                            {
                                q.push({a, b});
                                grid[a][b] = '0';
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
};



//不对原数组进行修改，使用标记数组标记陆地被修改成水
class Solution 
{
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool vis[301][301];//全局变量未初始化默认为false
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int ret = 0;//返回的结果
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                //判断是否为：陆地和陆地被修改
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    ++ret;//岛屿数量加1
                    //陆地进队列，标记陆地已修改，寻找4个方向的陆地
                    q.push({i, j});
                    vis[i][j] = true;
                    while (!q.empty())
                    {
                        auto [x, y] = q.front();
                        q.pop();
                        //寻找陆地
                        for (int dir = 0; dir < 4; ++dir)
                        {
                            int a = x + dx[dir], b = y + dy[dir];
                            if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b] == '1' && !vis[a][b])
                            {
                                q.push({a, b});
                                vis[a][b] = true;
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
};