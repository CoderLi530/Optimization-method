class Solution 
{
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        //多源最短路问题的思路
        //找到地图中的水域，使dist数组中对应位置改为0，并将对应位置进入队列
        int m = isWater.size(), n = isWater[0].size();//几排几列
        vector<vector<int>> dist(m, vector<int>(n, -1));//返回结果
        queue<pair<int, int>> q;//队列
        for (int i = 0; i < m; ++i)//记录水域，水域进队列
        {
            for (int j = 0; j < n; ++j)
            {
                if (isWater[i][j] == 1)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        //bfs
        //一层一层往外扩，每扩一层就+1
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