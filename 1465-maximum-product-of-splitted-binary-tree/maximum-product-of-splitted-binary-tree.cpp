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
    long SUM=0;
    // const int MOD = 1e9 + 7;

    long maxP=0;
    int totalSum(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int LS=totalSum(root->left);
        int RS=totalSum(root->right);
        long subTree=root->val+LS+RS;
        long remaingSubtree=SUM-subTree;
        maxP=max(maxP,remaingSubtree*subTree);

        return subTree;

    }
    int maxProduct(TreeNode* root) {
        if(root==NULL) return 0;
        maxP=0;
        SUM=totalSum(root);
        totalSum(root);
return maxP % 1000000007;
    
    }
};