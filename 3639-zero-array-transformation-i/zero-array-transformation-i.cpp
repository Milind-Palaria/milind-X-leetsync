class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 2, 0); 

        for(auto  q:queries){
           diff[q[0]]++;
           diff[q[1]+1]--;

        }

        int qmlsum=0;

        for(int i=0;i<n;i++){
            qmlsum+=diff[i];
            if(nums[i]>qmlsum) return false;
        }
        return true;
    }
};