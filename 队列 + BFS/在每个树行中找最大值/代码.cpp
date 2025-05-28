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
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int i = q.size();
            int num = INT_MIN;//整形最小值
            while (i--)
            {
                //先找出一层的最大值
                auto node = q.front();
                num = max(num, node->val);
                q.pop();
                //进行节点入队列
                if (node->left) q.push(node->left);
                if (node->right)q.push(node->right);
            }
            ret.push_back(num);
        }
        return ret;
    }
};