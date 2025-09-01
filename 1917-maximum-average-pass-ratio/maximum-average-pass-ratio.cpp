class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int totalClasses = classes.size();
        priority_queue<pair<double, pair<int,int>>> pq;

        for (int i = 0; i < totalClasses; i++) {
            double change = ((classes[i][0] *1.0 + 1.0) / (classes[i][1] * 1.0 + 1.0)) - ((classes[i][0] *1.0) / (classes[i][1] * 1.0));
            pq.push({change, {classes[i][0], classes[i][1]}}); 
        }

        while (extraStudents --) {
            auto p = pq.top();
            pq.pop();
            int num = p.second.first + 1, deno = p.second.second + 1;
            double change = ((num * 1.0 + 1.0) / (deno * 1.0 + 1.0)) - ((num * 1.0) / (deno * 1.0));
            pq.push({change, {num, deno}});
        }

        double sumNumerator = 0.0;

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            sumNumerator += (p.second.first * 1.0) / (p.second.second * 1.0); 
        }

        return (sumNumerator / totalClasses);
    }
};