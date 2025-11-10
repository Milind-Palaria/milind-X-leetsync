class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> ts;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i]==0 && ts.empty()) continue;
            if (nums[i] == 0 && !ts.empty()) {
                int tempTop = ts.top();
                ts.pop();
                while (!ts.empty()) {
                    if (tempTop != ts.top()) {
                        ans++;
                        tempTop = ts.top();
                    }
                    ts.pop();
                }
                ans++;
            } else if (!ts.empty() && ts.top() > nums[i]) {
                int tempTop=ts.top();
                ts.pop();
                ans++;
                while (!ts.empty() && ts.top() > nums[i]) {
                    if (tempTop != ts.top()) {
                        ans++;
                        tempTop = ts.top();
                    }
                    ts.pop();
                }
                ts.push(nums[i]);
            } else {
                ts.push(nums[i]);
            }
        }
        if (!ts.empty()) {
            int tempTop = ts.top();
            ts.pop();
            while (!ts.empty()) {
                if (tempTop != ts.top()) {
                    ans++;
                    tempTop = ts.top();
                }
                ts.pop();
            }
            ans++;
        }

        return ans;
    }
};