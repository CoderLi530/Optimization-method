class Solution 
{
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        //正难则反：遍历数组将陆地放进dist中并设置为0，再一层一层往外扩，找到最大距离的水域
        int n = grid.size();//正方形
        vector<vector<int>> dist(n, vector<int>(n, -1));//标记数组
        queue<pair<int, int>> q;//bfs队列
        int ret = 0;//注意返回结果是距离最远的数，不是走了几层
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        //bfs，一层一层递增数字
        while (!q.empty())
        {
            auto [a, b] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k)
            {
                int x = a + dx[k], y = b + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < n && dist[x][y] == -1)
                {
                    dist[x][y] = dist[a][b] + 1;
                    q.push({x, y});
                    ret = dist[x][y];
                }
            }
        }
        return ret == 0 ? -1 : ret;
    }
};