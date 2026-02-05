class Solution {
public:
    void dfs(TreeNode* root, vector<int>& res) {
        if (root == NULL) return;

        res.push_back(root->val);
        dfs(root->left, res);
        dfs(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
};
