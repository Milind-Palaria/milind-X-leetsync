class Solution {
public:
    int n;

    bool dfs(vector<vector<int>> &adj, vector<int> &vis, string &colors, 
             vector<vector<int>> &count, vector<int> &visp, int node, int &ans) 
    {
        vis[node] = 1;
        visp[node] = 1;

        for (int next : adj[node]) {
            if (!vis[next]) {
                if (dfs(adj, vis, colors, count, visp, next, ans))
                    return true;  // cycle detected
            } else if (visp[next]) {
                return true;  // back edge → cycle
            }

            for (int c = 0; c < 26; ++c) {
                count[node][c] = max(count[node][c], count[next][c]);
            }
        }

        count[node][colors[node] - 'a'] += 1;
        ans = max(ans, count[node][colors[node] - 'a']);

        visp[node] = 0;  // remove from recursion stack
        return false;
    }

    int largestPathValue(string colors, vector<vector<int>> &edges) {
        n = colors.size();
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> vis(n, 0), visp(n, 0);
        vector<vector<int>> count(n, vector<int>(26, 0));
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                if (dfs(adj, vis, colors, count, visp, i, ans)) {
                    return -1;  // cycle detected
                }
            }
        }

        return ans;
    }
};