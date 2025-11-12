class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }


    int minOperations(vector<int>& nums) {
        int n=nums.size();

        int cnt1 = 0;
        for (int x : nums) if (x == 1) ++cnt1;
        if (cnt1 > 0) return n - cnt1;

        int flag=0;
        int len=INT_MAX;

        for(int i=0; i<n; i++){
            int g = nums[i];
            for(int j=i; j<n; j++){
                int temp = gcd(g, nums[j]);
                if(temp == 1){
                    flag=1;
                    len=min(len, (j-i+1));
                }
                g= temp;
            }
        }    
        if(flag==0) return -1;

        return len-1 + n-1 ;
    }
};