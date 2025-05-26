/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        //root为空，返回空数组
        +
        if (root == NULL) return {};
        queue<TreeNode*> q;//存放节点的队列
        vector<vector<int>> ret;//返回的数组
        q.push(root);//入节点
        int flag = 1;//判断偶数层进行逆序
        while (!q.empty())
        {
            //先将左右节点入队列，偶数层要逆序
            int i = q.size();
            vector<int> tmp;
            while (i--)
            {
                if (q.front()->left) q.push(q.front()->left);//节点有可能为空，判断一下
                if (q.front()->right) q.push(q.front()->right);//同上
                tmp.push_back(q.front()->val);
                q.pop();
            }
            //偶数层需要逆序
            if (flag % 2 == 0) reverse(tmp.begin(), tmp.end());
            ret.push_back(tmp);
            ++flag;
        }
        //遍历结束，ret就是最终的答案
        return ret;
    }
};