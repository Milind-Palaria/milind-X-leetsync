class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n3 = nums.size(), n = n3 / 3;
        vector<long long> part1(n3 + 1),part2(n3+1);
        long long sum = 0;
        priority_queue<int> ql;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            ql.push(nums[i]);
              part2[i]=sum;
        }
        part1[n-1] = sum;
        for (int i = n; i < n * 2; ++i) {
            sum += nums[i];
            ql.push(nums[i]);
            sum -= ql.top();
            ql.pop();
            part1[i] = sum;
        }

       sum=0;
        priority_queue<int, vector<int>, greater<int>> qr;
        for (int i = n * 3 - 1; i >= n * 2; --i) {
         sum += nums[i];
            qr.push(nums[i]);
              part2[i]=sum;
        }

        for (int i = n * 2 - 1; i >= n; --i) {
          sum += nums[i];
            qr.push(nums[i]);
          sum -= qr.top();

            qr.pop();
            part2[i]=sum;
           
        }
         
        long long ans=1e18;
        for(int i=n-1;i<2*n;i++)
        {
       
             ans = min(ans, part1[i] - part2[i+1]);
        }
        return ans;
    }
};