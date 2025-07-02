class Solution 
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        //1. 建图
        unordered_map<int, vector<int>> edges; // 建立邻接表
        vector<int> in(numCourses); // 记录顶点的入度，大小和题目一致
        
        //2. 在图中存放数据
        for (auto& e : prerequisites) // e所指向的是vector
        {
            int a = e[0], b = e[1]; // b -> a
            edges[b].push_back(a); // 创建edges[b]或者找到edges[b]，数据添加
            in[a]++; // 入度增加
        }

        //3. 进行拓扑排序
        //(1) 将入度为0的顶点加入到队列中
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (in[i] == 0) q.push(i); //不是放入度值
        } 
        //(2) bfs
        while (!q.empty())
        {
            int x = q.front(); q.pop(); // 取出值，删除值
            // 在邻接表中对应的vector中的值的入度值需要-1
            for (int num : edges[x]) // edges[x]为对应的vector
            {
                in[num]--;
                // 入度值为0进入队列
                if (in[num] == 0) q.push(num);
            }
        }
        //(3) 检验是否为有环
        for (int i = 0; i < numCourses; ++i)
        {
            if (in[i]) return false; // 有环返回false
        }
        return true;
    }
};