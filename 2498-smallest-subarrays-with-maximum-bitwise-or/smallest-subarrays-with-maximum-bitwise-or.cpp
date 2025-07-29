class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v(30);
        for(int i=0;i<n;i++){
            int val = nums[i];
            for(int k=0;k<30;k++){
                if(val & (1<<k)) v[k].push_back(i);
            }
        }
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            int maxi = 1;
            for(int k=0;k<30;k++){
                int i1 = lower_bound(v[k].begin(),v[k].end(),i) - v[k].begin();
                if(i1 == v[k].size() || (nums[i] & (1<<k))) continue;
                maxi = max(maxi,(v[k][i1] - i) + 1);
            }
            ans[i] = maxi;
        }
        return ans;
    }
};