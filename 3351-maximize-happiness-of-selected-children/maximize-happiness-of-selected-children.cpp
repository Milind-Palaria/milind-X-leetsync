class Solution {
public:
    long long maximumHappinessSum(vector<int>& happi ,int k) {
        long long n= happi.size();
        sort(happi.begin(),happi.end(),greater<int>());
        long long cnt=0;
       
        cnt= happi[0]; long long i=1, diff=1; k--;
         while(k>0){
            if(happi[i]-diff>0) {
                cnt=cnt+(happi[i]-diff);
                diff++; i++;
            }
            else {
                diff++; i++;
            }
            k--;
         }
        return cnt;
    }
};