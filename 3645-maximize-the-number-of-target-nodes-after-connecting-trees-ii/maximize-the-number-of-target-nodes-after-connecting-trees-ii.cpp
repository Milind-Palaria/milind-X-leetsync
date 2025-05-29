class Solution {
public:
    pair<int, int> bfsParityCount(const vector<vector<int>>& adj, vector<int>& parity) {
        int evenCount = 0, oddCount = 0;
        int level = 0;

        queue<pair<int, int>> q;
        q.push({0, -1});  

        while (!q.empty()) {
            int size = q.size();
            if (level % 2 == 0) evenCount += size;
            else oddCount += size;

            for (int i = 0; i < size; ++i) {
                auto [node, parent] = q.front();
                q.pop();
                parity[node] = level % 2;

                for (int neighbor : adj[node]) {
                    if (neighbor != parent) {
                        q.push({neighbor, node});
                    }
                }
            }

            level ^= 1; 
        }

        return {evenCount, oddCount};
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;

        vector<vector<int>> adj1(n1);
        vector<vector<int>> adj2(n2);

        for (const auto& edge : edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }

        for (const auto& edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        vector<int> parity1(n1, -1), parity2(n2, -1);

        auto [even1, odd1] = bfsParityCount(adj1, parity1);
        auto [even2, odd2] = bfsParityCount(adj2, parity2);

        int add = max(even2, odd2);
        vector<int> result(n1);

        for (int i = 0; i < n1; ++i) {
            if (parity1[i] == 0)
                result[i] = even1 + add;
            else
                result[i] = odd1 + add;
        }

        return result;
    }
};