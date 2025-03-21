class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ing, vector<string>& supplies) {
        unordered_map<string,vector<string>> adj;
        unordered_map<string,int> deg;
        int n=recipes.size();
        int m=ing.size();
        /// building a directed graph where ingredients point rowrds the recipe and the  recording the dependencies of each recipe 
        for(int i=0;i<n;i++){
            for(auto it:ing[i]){
                adj[it].push_back(recipes[i]);
            }
            deg[recipes[i]]=ing[i].size();
        }
        // use topo sort for finding te order of the recipes 
        // push the leaf nodes(supplies) onto the queue and start the bfs

        vector<string> ans;
        queue<string> q;
        for(auto it:supplies){
            q.push(it);
        }

        // start the bfs;


        while(!q.empty()){
            string cur= q.front();
            q.pop();

            // check adjacent nodes for this current node, (i.e checking which recipes require this supply)
            for(auto it:adj[cur]){
                deg[it]--;
                if(deg[it]==0){
                    ans.push_back(it);
                    q.push(it);
                }
            }
        }

        return ans;



    }
};