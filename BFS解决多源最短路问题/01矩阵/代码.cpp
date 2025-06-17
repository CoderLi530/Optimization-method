class Solution 
{
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        //统计出所有的0
        int m = mat.size(), n = mat[0].size();
        //二维数组进行初始化-1
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        //dist中存储0，0进入队列
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
                {
                    if (mat[i][j] == 0) 
                    {
                        dist[i][j] = 0;
                        q.push({i, j});
                    }
                }    
        }
        //bfs
        while (!q.empty())
        {
            auto [a, b] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k)
            {
                int x = a + dx[k], y = b + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && dist[x][y] == -1)
                {
                    dist[x][y] = dist[a][b] + 1;
                    q.push({x, y});
                }
            }
        }
        //返回结果
        return dist;
    }
};