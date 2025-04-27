class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        for (int i = 0; i <= n - 3; i++) {
            int first = nums[i];
            int second = nums[i + 1];
            int third = nums[i + 2];
                if(second % 2 == 0){
            if (first + third == second / 2) {
                cnt++;
            }
         }
        }

        return cnt;
    }
};