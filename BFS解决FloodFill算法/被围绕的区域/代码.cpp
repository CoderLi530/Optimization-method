//冗余代码
class Solution 
{
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
public:
    void solve(vector<vector<char>>& board) 
    {
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> q;
        //1. 将最边缘的'O'修改为其他字符
        //遍历最上边
        for (int i = 0; i < n; ++i)
        {
            if (board[0][i] == 'O')
            {
                q.push({0, i});
                board[0][i] = 'Y';
                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int j = 0; j < 4; ++j)
                    {
                        int a = x + dx[j], b = y + dy[j];
                        if (a >= 0 & a < m && b >= 0 && b < n && board[a][b] == 'O')
                        {
                            q.push({a, b});
                            board[a][b] = 'Y';
                        }
                    }
                }
            }
        }
        //遍历最下边
        for (int i = 0; i < n; ++i)
        {
            if (board[m - 1][i] == 'O')
            {
                q.push({m - 1, i});
                board[m - 1][i] = 'Y';
                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int j = 0; j < 4; ++j)
                    {
                        int a = x + dx[j], b = y + dy[j];
                        if (a >= 0 & a < m && b >= 0 && b < n && board[a][b] == 'O')
                        {
                            q.push({a, b});
                            board[a][b] = 'Y';
                        }
                    }
                }
            }
        }
        //遍历最左边
        for (int i = 0; i < n; ++i)
        {
            if (board[i][0] == 'O')
            {
                q.push({i, 0});
                board[i][0] = 'Y';
                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int j = 0; j < 4; ++j)
                    {
                        int a = x + dx[j], b = y + dy[j];
                        if (a >= 0 & a < m && b >= 0 && b < n && board[a][b] == 'O')
                        {
                            q.push({a, b});
                            board[a][b] = 'Y';
                        }
                    }
                }
            }
        }
        //遍历最右边
        for (int i = 0; i < n; ++i)
        {
            if (board[i][n - 1] == 'O')
            {
                q.push({i, n - 1});
                board[i][n - 1] = 'Y';
                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int j = 0; j < 4; ++j)
                    {
                        int a = x + dx[j], b = y + dy[j];
                        if (a >= 0 & a < m && b >= 0 && b < n && board[a][b] == 'O')
                        {
                            q.push({a, b});
                            board[a][b] = 'Y';
                        }
                    }
                }
            }
        }
        //被围绕的区域进行修改
        for (int i = 1; i < m - 1; ++i)
        {
            for (int j = 1; j < n -1; ++j)
            {
                if (board[i][j] == 'O')
                {
                    q.push({i, j});
                    board[i][j] = 'X';
                    while (!q.empty())
                    {
                        auto [x, y] = q.front();
                        q.pop();
                        for (int k = 0; k < 4; ++j)
                        {
                            int a = x + dx[k], b = y + dy[k];
                            if (a >= 0 & a < m && b >= 0 && b < n && board[a][b] == 'O')
                            {
                                q.push({a, b});
                                board[a][b] = 'X';
                            }
                        }
                    }
                }
            }
        }
        //还原
        for (int i = 0; i < n; ++i)
        {
            if (board[0][i] == 'Y')
            {
                q.push({0, i});
                board[0][i] = 'O';
                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int j = 0; j < 4; ++j)
                    {
                        int a = x + dx[j], b = y + dy[j];
                        if (a >= 0 & a < m && b >= 0 && b < n && board[a][b] == 'Y')
                        {
                            q.push({a, b});
                            board[a][b] = 'O';
                        }
                    }
                }
            }
        }
        //遍历最下边
        for (int i = 0; i < n; ++i)
        {
            if (board[m - 1][i] == 'Y')
            {
                q.push({m - 1, i});
                board[m - 1][i] = 'O';
                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int j = 0; j < 4; ++j)
                    {
                        int a = x + dx[j], b = y + dy[j];
                        if (a >= 0 & a < m && b >= 0 && b < n && board[a][b] == 'Y')
                        {
                            q.push({a, b});
                            board[a][b] = 'O';
                        }
                    }
                }
            }
        }
        //遍历最左边
        for (int i = 0; i < n; ++i)
        {
            if (board[i][0] == 'Y')
            {
                q.push({i, 0});
                board[i][0] = 'O';
                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int j = 0; j < 4; ++j)
                    {
                        int a = x + dx[j], b = y + dy[j];
                        if (a >= 0 & a < m && b >= 0 && b < n && board[a][b] == 'Y')
                        {
                            q.push({a, b});
                            board[a][b] = 'O';
                        }
                    }
                }
            }
        }
        //遍历最右边
        for (int i = 0; i < n; ++i)
        {
            if (board[i][n - 1] == 'Y')
            {
                q.push({i, n - 1});
                board[i][n - 1] = 'O';
                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int j = 0; j < 4; ++j)
                    {
                        int a = x + dx[j], b = y + dy[j];
                        if (a >= 0 & a < m && b >= 0 && b < n && board[a][b] == 'Y')
                        {
                            q.push({a, b});
                            board[a][b] = 'O';
                        }
                    }
                }
            }
        }
    }
};


//以上代码太多重复代码，应该将重复代码写成子函数进行调用。
class Solution 
{
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int m, n;
public:
    void solve(vector<vector<char>>& board) 
    {
        m = board.size(), n = board[0].size();
        //1. 对边界的'O'进行修改
        for (int i = 0; i < n; ++i)
        {
            if (board[0][i] == 'O') bfs(board, 0, i);
            if (board[m - 1][i] == 'O') bfs(board, m - 1, i);
        }
        for (int j = 0; j < m; ++j)
        {
            if (board[j][0] == 'O') bfs(board, j, 0);
            if (board[j][n - 1] == 'O') bfs(board, j, n -1);
        }
        //2. 层序遍历将'O'修改成'X',顺便进行还原
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
    }
    void bfs(vector<vector<char>>& board, int i, int j)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        board[i][j] = 'Y';
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k)
            {
                int a = x + dx[k], b = y + dy[k];
                if (a >= 0 && a < m && b >= 0 && b < n && board[a][b] == 'O')
                {
                    q.push({a, b});
                    board[a][b] = 'Y';
                }
            }
        }
    }
};