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
    void dfs(TreeNode* node, string path, vector<string>& ans) {
        if (node == nullptr)
            return;

        // Add current node to path
        if (!path.empty())
            path += "->";

        path += to_string(node->val);

        // If it's a leaf, store the path
        if (node->left == nullptr && node->right == nullptr) {
            ans.push_back(path);
            return;
        }

        dfs(node->left, path, ans);
        dfs(node->right, path, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(root, "", ans);
        return ans;
    }
};