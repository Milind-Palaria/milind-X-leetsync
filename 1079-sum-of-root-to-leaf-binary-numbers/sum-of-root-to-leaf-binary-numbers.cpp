class Solution {
public:
    int result = 0;

    void dfs(TreeNode* node, int bin) {
        if (!node) return;
        bin = (bin << 1) | node->val;
        if (!node->left && !node->right) result += bin;
        dfs(node->left, bin);
        dfs(node->right, bin);
    }

    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return result;
    }
};