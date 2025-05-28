class Solution {
    int dfs(int curr, int parent, vector<vector<int>>& adjList, int k) {
        if(k == 0) return 1;
        int ans = 0;
        for(int next: adjList[curr]) {
            if(next != parent)
                ans += dfs(next, curr, adjList, k - 1);
        }
        return ans + 1;
    }
    vector<vector<int>> createGraph(vector<vector<int>>& edges) {
        vector<vector<int>> adjList(edges.size() + 1);
        for(int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        return adjList;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1, maxNodes = 0;
        vector<vector<int>> adjList1 = createGraph(edges1);
        vector<vector<int>> adjList2 = createGraph(edges2);
        vector<int> ans(n);
        if(k) {
            for(int i = 0; i < m; i++) {
                maxNodes = max(maxNodes, dfs(i, -1, adjList2, k - 1));
            }
        }
        for(int i = 0; i < n; i++) {
            ans[i] = dfs(i, -1, adjList1, k) + maxNodes;
        }
        return ans;
    }
};