#define ll long long

class Solution {
public:
    int rob(TreeNode* root) {
        auto res = dfs(root);
        ll ans = max(res.first, res.second);
        return (int)ans;
    }

private:
    pair<long long, long long> dfs(TreeNode* node) {
        if (!node)
            return {0LL, 0LL};

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        ll rob = node->val + left.second + right.second;
        ll skip = max(left.first, left.second) + max(right.first, right.second);

        return {rob, skip};
    }
};
