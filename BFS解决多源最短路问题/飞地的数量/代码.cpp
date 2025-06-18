class Solution 
{
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool vis[501][501] = {false};
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        //正难则反：可以找可以离开网格边界的陆地数量
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        int ret = 0;//返回结果
        //上下边界的陆地
        for (int j = 0; j < n; ++j)
        {
            if (grid[0][j] == 1) q.push({0, j});
            if (grid[m - 1][j] == 1) q.push({m - 1, j});
        }
        //左右边界的陆地
        for (int i = 0; i < m; ++i)
        {
            if (grid[i][0] == 1) q.push({i, 0});
            if (grid[i][n - 1] == 1) q.push({i, n - 1});
        }
        //多源最短路问题 
        while (!q.empty())
        {
            auto[a, b] = q.front();
            q.pop();
            vis[a][b] = true;//该操作有点重复，可以在遍历边界陆地时进行标记。
            //四个方向的陆地
            for (int k = 0; k < 4; ++k)
            {
                int x = a + dx[k], y = b + dy[k];
                if (x >= 0 && x < m && y >=0 && y < n && grid[x][y] == 1 && !vis[x][y])
                {
                    q.push({x, y});
                    vis[x][y] = true;
                }
            }
        }
        //遍历数组，记录没有被标记的1
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1 && !vis[i][j]) ++ret;
            }
        }
        //返回结果
        return ret;
    }
};