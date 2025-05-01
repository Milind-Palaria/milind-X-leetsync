class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0;
        int right = min(tasks.size(), workers.size());

        while (left < right) {
            int mid = left + (right - left + 1) / 2;

            deque<int> cachedWorkers;
            int currPills = pills;
            int workersIdx = workers.size() - 1;
            bool isAssigned = true;

            for (int i = mid - 1; i >= 0; i--) {
                int task = tasks[i];

                if (!cachedWorkers.empty() && task <= cachedWorkers.front()) {
                    cachedWorkers.pop_front();
                } else if (workersIdx >= 0 && task <= workers[workersIdx]) {
                    workersIdx--;
                } else {
                    while (workersIdx >= 0 && task <= workers[workersIdx] + strength) {
                        cachedWorkers.push_back(workers[workersIdx]);
                        workersIdx--;
                    }
                    if (cachedWorkers.empty() || currPills == 0) {
                        isAssigned = false;
                        break;
                    }
                    cachedWorkers.pop_back();
                    currPills--;
                }
            }
            
            if (isAssigned) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};