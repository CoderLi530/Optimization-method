//bfs
//时间复杂度O(M+N) 空间复杂度O(M+N)
class Solution 
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        //1. 建图
        unordered_map<int, vector<int>> edges; //邻接表
        vector<int> in(numCourses); //入度表
        vector<int> ret; //返回结果

        //2. 存放数据
        for (auto& e : prerequisites)
        {
            int a = e[0], b = e[1]; //b --> a
            edges[b].push_back(a); //vector增加数据
            in[a]++; //数据的入度值+1
        }

        //3. 进行拓扑排序
        //(1) 将入度值为0的值存放到队列中
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (in[i] == 0) 
            {
                q.push(i); //将数据存放到队列中，而不是入度值的数量
                ret.push_back(i); //入度值为0进入ret
            }
        }
        //(2) 进行bfs
        while(!q.empty())
        {
            int x = q.front(); q.pop(); //取出数据
            //所指向的数据的入度值要--
            for (int num : edges[x]) //edgs[x]：x对应的vector
            {
                in[num]--; //入度值--
                if (in[num] == 0) 
                {
                    q.push(num); //入度值为0进入队列
                    ret.push_back(num); //入度值为0的值进入ret
                }
            }
        }
        for (int i = 0; i < numCourses; ++i)
        {
            if (in[i]) return {}; //入度值表中还有数据，返回空数组
        }
        return ret;
    }
};

//dfs
//时间复杂度O(M+N) 空间复杂度O(M+N)
class Solution
{
public:
    bool dfs(vector<vector<int>> &edges, vector<int> &vis, int i)
    {
        // 情况1：当前节点正在搜索中（当前DFS路径上再次遇到）→ 存在环！
        if (vis[i] == 1) return false;
        // 情况2：当前节点已搜索完成（其所有后代均无环）→ 直接返回无环
        if (vis[i] == 2) return true;
    
        // 情况3：节点未搜索，标记为“正在搜索”（加入当前DFS路径）
        vis[i] = 1;
    
        // 递归遍历当前节点的所有后代（后续课程）
        for (auto x : edges[i])
        {
            // 若任一后代存在环，当前节点所在路径也有环 → 返回false
            if (!dfs(edges, vis, x)) return false;
        }
    
        // 所有后代均无环，标记当前节点为“搜索完成”（退出当前DFS路径）
        vis[i] = 2;
        return true; // 当前子图无环
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // dfs
        vector<vector<int>> edges(numCourses);
        vector<int> vis(numCourses); // 0表示未搜索，1表示正在搜索中，2表示搜索完成
        for (auto arr : prerequisites)
        {
            edges[arr[1]].push_back(arr[0]); //对于[1, 0]，由0->1，先学习0再学习1
        }
        for (int i = 0; i < numCourses; ++i)
        {
            //未搜索的课程才进行dfs
            if (vis[i] == 0)
            {
                if (!dfs(edges, vis, i)) return false;
            }
        }
        return true;
    }
};