class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        std::vector<std::vector<std::pair<int, int>>> adj(n, std::vector<std::pair<int, int>>{});
        std::unordered_set<int> seen;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        for (const auto& m : meetings) {
            const int u = m[0];
            const int v = m[1];
            const int t = m[2];
            adj[u].emplace_back(t, v);
            adj[v].emplace_back(t, u);
        }

        pq.emplace(0, 0);
        pq.emplace(0, firstPerson);
        while (!pq.empty()) {
            const auto cur = pq.top();
            pq.pop();
            const int time = cur.first;
            const int person = cur.second;

            if (0 < seen.count(person)) {
                continue;
            }

            seen.insert(person);
            for (const auto& nb : adj[person]) {
                const int nb_time = nb.first;
                const int nb_person = nb.second;
                if (0 == seen.count(nb_person) && time <= nb_time) {
                    pq.emplace(nb_time, nb_person);
                }
            }
        }

        std::vector<int> insightful(seen.begin(), seen.end());

        return insightful;
    }
};