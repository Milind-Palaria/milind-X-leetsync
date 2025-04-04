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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root || (!root->left && !root->right)){
            return root;
        }
        unordered_map<TreeNode*,TreeNode*> comb;
        queue<TreeNode*> q;
        stack<pair<TreeNode*,int>> s;
        priority_queue<pair<int,TreeNode*>> pq;
        s.push({root,0});
        while(!s.empty()){
            auto [temp,len] = s.top();s.pop();
            if(!temp->left && !temp->right){
                pq.push({len,temp});
                continue;
            }
            if(temp->left){
                comb[temp->left] = temp;
                s.push({temp->left,len + 1});
            }
            if(temp->right){
                comb[temp->right] = temp;
                s.push({temp->right,len + 1});
            }
        }
        q.push(pq.top().second);
        int max_d = pq.top().first;pq.pop();
        while(!pq.empty() && max_d == pq.top().first){
            q.push(pq.top().second);pq.pop();
        }
        if(q.size() == 1){
            return q.front();
        }
        unordered_map<TreeNode*,bool> visit;
        while(q.size() != 1){
            int len = q.size();
            for(int i = 0; i < len;i++){
                TreeNode* temp = q.front();q.pop();
                TreeNode* parent = comb[temp];
                if(parent && !visit[parent]){
                    visit[parent] = true;
                    q.push(parent);
                }
            }
        }
        return q.front();
    }
};