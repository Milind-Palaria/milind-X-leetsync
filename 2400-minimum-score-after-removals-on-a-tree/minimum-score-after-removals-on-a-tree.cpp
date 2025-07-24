class Solution {
public:
int time=0;
    int dfs(int node, vector<int>& v, vector<int>& nums, vector<vector<int>>& tree, int parent,vector<pair<int,int>> &times) {
        v[node] = nums[node];
        times[node].first=time++;
        for (int j = 0; j < tree[node].size(); j++) {
            if (tree[node][j] == 1 && j != parent) {
                v[node] ^= dfs(j, v, nums, tree, node,times);
            }
        }
        times[node].second=time++;
        return v[node];
    }

    int minimumScore(vector<int>& n, vector<vector<int>>& edges) {
        int N = n.size();
        vector<vector<int>> tree(N, vector<int>(N, 0));

        for (int i = 0; i < edges.size(); i++) {
            tree[edges[i][0]][edges[i][1]] = 1;
            tree[edges[i][1]][edges[i][0]] = 1;
        }
        vector<pair<int,int>> times(N,{0,0});
        int total = 0;
        for (int i = 0; i < N; i++) total ^= n[i];

        vector<int> v(N, 0);
        v[0] = dfs(0, v, n, tree, -1,times);

        // i chose 0 as root node
        int ans=INT_MAX;
        for(int i=1;i<N;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(times[i].first<times[j].first && times[j].second<times[i].second)
                {
                    int a=v[i];
                    int b=v[j];
                    a=a^b;
                    ans=min(ans,max({total^a^b,a,b})-min({total^a^b,a,b}));
                }
                else if(times[j].first<times[i].first && times[i].second<times[j].second)
                {
                    int a=v[i];
                    int b=v[j];
                    b=b^a;
                    ans=min(ans,max({total^a^b,a,b})-min({total^a^b,a,b}));
                }
                else
                {
                    int a=v[i];
                    int b=v[j];
                    ans=min(ans,max({total^a^b,a,b})-min({total^a^b,a,b}));
                }
            }
        }

        return ans;
    }
};