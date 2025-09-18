class TaskManager {
public:
    priority_queue<pair<int, int>> taskPriority;
    unordered_map<int, int> priorityMap;
    unordered_map<int, int> userMap;

    TaskManager(vector<vector<int>>& tasks) {
        for(auto &task: tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];

            add(userId, taskId, priority);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskPriority.push({priority, taskId});
        priorityMap[taskId] = priority;
        userMap[taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        priorityMap[taskId] = newPriority;
        taskPriority.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        userMap.erase(taskId);
        priorityMap.erase(taskId);
    }
    
    int execTop() {
        if(userMap.size() == 0) return -1;

        int taskId = -1, priority = -1;

        while(userMap.find(taskId) == userMap.end() or priorityMap[taskId] != priority) {
            priority = taskPriority.top().first;
            taskId = taskPriority.top().second;
            taskPriority.pop();
        }

        int userId = userMap[taskId];

        rmv(taskId);

        return userId;
    }
};