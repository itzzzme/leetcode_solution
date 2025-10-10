class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {};
        return rec(1, n);
    }

    vector<TreeNode*> rec(int start, int end) {
        vector<TreeNode*> Trees;

        if (start > end) {
            Trees.push_back(nullptr);
            return Trees;
        }

        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left = rec(start, i - 1);

            vector<TreeNode*> right = rec(i + 1, end);

            for (TreeNode* left : left) {
                for (TreeNode* right : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    Trees.push_back(root);
                }
            }
        }

        return Trees;
    }
};
