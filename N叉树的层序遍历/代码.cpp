class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        //root没有节点
        if (root == NULL) return {};
        queue<Node*> q;//队列
        vector<vector<int>> ret;//返回的数组
        q.push(root);//头节点先入队列
        while (!q.empty())
        {
            int i = q.size();//进行分层，判断出队列几次
            vector<int> num;
            while (i--)
            {
                //先将子节点进队列
                for (auto& node : q.front()->children) q.push(node);
                //出队列，ret存放数据
                num.push_back(q.front()->val);
                q.pop();
            }
            ret.push_back(num);
        }
        //队列为空，层序遍历完毕
        return ret;
    }
};