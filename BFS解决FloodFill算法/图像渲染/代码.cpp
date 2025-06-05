class Solution 
{
    //四个方向的变化值
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        //记录初始像素的颜色
        int start = image[sr][sc];
        //初始像素的颜色和color相同直接返回。四个方向的像素颜色要么和color相同不用修改，要么和color不相同不能修改
        if (start == color) return image;
        int m = image.size(), n = image[0].size();
        //使用队列继续层序遍历
        //存放下标
        queue<pair<int, int>> q;
        q.push({sr, sc});//存放初始像素
        while (!q.empty())
        {
            //先出队列，修改颜色，然后放入四个方向颜色相同的像素
            auto [x, y] = q.front();
            q.pop();
            image[x][y] = color;
            //四个方向有可能是边界方向，注意判断是否越界
            for (int i = 0; i < 4; ++i)
            {
                //判断一个方向的像素是否越界，不越界并且和初始元素颜色相同放进队列
                int a = dx[i] + x, b = dy[i] + y;
                if (a >= 0 && a < m && b >= 0 && b < n && image[a][b] == start)
                {
                    q.push({a, b});
                }
            }
        }
        return image;
    }
};