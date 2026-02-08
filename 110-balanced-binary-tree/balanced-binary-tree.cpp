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
    int validity(TreeNode* node) {
        if (node == NULL) return 0;
        int leftheight = validity(node->left);
        if (leftheight == -1) return -1;

        int rightheight = validity(node->right);
        if (rightheight == -1) return -1;
        if (abs(leftheight - rightheight) > 1) {
            return -1;
        }
        return 1 + max(leftheight, rightheight);
    }
    bool isBalanced(TreeNode* root) {   
        int valid = validity(root);
        if (valid == -1) return false;
        return true;
    }
};