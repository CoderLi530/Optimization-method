//不对原数组进行修改，创建一个布尔数组
class Solution 
{
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool vis[51][51] = {false};//局部变量初始化为false，表示岛屿未修改
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        queue<pair<int, int>> q;//队列
        int ret = 0;//返回的结果
        int m = grid.size(), n = grid[0].size();//几排几列
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                //判断是否为1，为1入队列，计数加一，查看四个方向的岛屿
                int count = 0;
                if (grid[i][j] == 1 && !vis[i][j])//岛屿没有进行修改（计算）
                {
                    q.push({i, j});
                    ++count;
                    while (!q.empty())//队列不为空，存在岛屿
                    {
                        auto [x, y] = q.front();
                        q.pop();
                        vis[x][y] = true;//进行岛屿修改
                        //四个方向的岛屿
                        for (int k = 0; k < 4; ++k)
                        {
                            int a = x + dx[k], b = y + dy[k];
                            //注意四个方向的边界问题
                            if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b] == 1 && !vis[a][b])        
                            {
                                q.push({a, b});
                                ++count;
                                vis[a][b] = true;//不设置已修改，会重复计算
                            }
                        }
                    }
                }
                //比较出较大的岛屿数量
                ret = max(ret, count);
            }
        }
        return ret;
    }
};