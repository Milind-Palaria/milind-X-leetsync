class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int perimeter = 0;
        for(int i = n-1; i>=2; i--){
            int c = nums[i];
            int b = nums[i-1];
            int a = nums[i-2];
            if(a + b > c){
                perimeter = max(a+b+c, perimeter);
            }
        }
        return perimeter;
    }
};