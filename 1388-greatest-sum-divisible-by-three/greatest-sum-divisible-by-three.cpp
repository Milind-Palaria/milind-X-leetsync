class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int tw_1 = INT_MAX, tw_2 = INT_MAX, on_1 = INT_MAX, on_2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            sum += (nums[i]);
            if (nums[i] % 3 == 1) {
                if (nums[i] <= on_1) {
                    on_2 = on_1;
                    on_1 = nums[i];
                } else {
                    on_2 = min(on_2, nums[i]);
                }
            }
            if (nums[i] % 3 == 2) {
                if (nums[i] <= tw_1) {
                    tw_2 = tw_1;
                    tw_1 = nums[i];
                } else {
                    tw_2 = min(tw_2, nums[i]);
                }
            }
        }
        if (sum % 3 == 0) {
            return sum;
        }
        if (sum % 3 == 1) {
            int mini = INT_MAX;
            if (on_1 != INT_MAX) {
                mini = min(mini, on_1);
            }
            if (tw_1 != INT_MAX && tw_2 != INT_MAX) {
                mini = min(mini, tw_1 + tw_2);
            }
            sum -= mini;
            return sum;
        }
        if (sum % 3 == 2) {
            int mini = INT_MAX;
            if (tw_1 != INT_MAX) {
                mini = min(mini, tw_1);
            }
            cout<<tw_1<<endl;
            if (on_1 != INT_MAX && on_2 != INT_MAX) {
                mini = min(mini, on_1 + on_2);
            }
            
            sum -= mini;
            return sum;
        }
        return sum;
    }
};