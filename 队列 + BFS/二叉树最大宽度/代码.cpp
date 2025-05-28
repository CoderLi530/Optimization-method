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
    int widthOfBinaryTree(TreeNode* root) {
        //只有根节点返回1
        if (root->left == nullptr && root->right == nullptr) return 1;
        vector<pair<TreeNode*, unsigned int>> v;//存放节点和下标
        v.push_back({root, 1});
        unsigned int ret = 1;//返回值
        while (!v.empty())
        {
            //比较最长宽度
            auto& [x1, y1] = v.front();
            auto& [x2, y2] = v.back();
            ret = max(ret, y2 - y1 + 1);
            //新节点入数组
            vector<pair<TreeNode*, unsigned int>> tmp;
            for (auto& [x, y] : v)
            {
                if (x->left) tmp.push_back({x->left, y * 2});
                if (x->right) tmp.push_back({x->right, y * 2 + 1});
            }    
            //覆盖原数组
            v = tmp;
        }
        //遍历完毕，ret保存了最终结果
        return ret;
    }
};