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

