class Solution 
{
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int vis[101][101] = {false};
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        queue<pair<int, int>> q;//创建队列
        int m = maze.size(), n = maze[0].size();
        int ret = 0;//返回结果
        q.push({entrance[0], entrance[1]});//记录起点
        vis[entrance[0]][entrance[1]] = true;//标记位置
        while (!q.empty())
        {
            //进行层序遍历，一层一层遍历，直到到达边界点
            int i = q.size();
            while (i--)
            {
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k)
                {
                    int a = x + dx[k], b = y + dy[k];
                    if (a >= 0 && a < m && b >= 0 && b < n && maze[a][b] == '.' && !vis[a][b])
                    {
                        q.push({a, b});
                        vis[a][b] = true;
                        if (a == 0 || a == m -1 || b == 0 || b == n -1) return ++ret;
                    }
                }
            }
            ++ret;//每次循环加一层
        }
        return -1;//没有找到出口
    }
};