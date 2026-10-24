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
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int prev = 0, count = 0, maxCount = 0;
        bool hasPrev = false;

        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;

            inorder(node->left);

            if (hasPrev && node->val == prev)
                count++;
            else
                count = 1;

            if (count > maxCount) {
                maxCount = count;
                ans.clear();
                ans.push_back(node->val);
            } else if (count == maxCount) {
                ans.push_back(node->val);
            }

            prev = node->val;
            hasPrev = true;

            inorder(node->right);
        };

        inorder(root);
        return ans;
    }
};