class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level(levelSize);
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                int index;
                if (flag == 0)
                    index = i;                       
                else
                    index = levelSize - 1 - i;      
                level[index] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(level);
            flag = 1 - flag; 
        }
        return result;
    }
};
