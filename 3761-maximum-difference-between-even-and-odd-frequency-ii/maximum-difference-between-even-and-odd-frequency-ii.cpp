class Solution {
    int dp[30001][2][2];
public:
    int solve(const string& s, char a, char b, const int k)
    {
        //e:o :: 0:1
        int ans=INT_MIN;
       
        dp[0][0][0] = INT_MAX;
        dp[0][0][1] = INT_MAX;
        dp[0][1][0] = INT_MAX;
        dp[0][1][1] = INT_MAX;
        int f1=0;
        int f2=0;
        int lasta=-1;
        int lastb=-1;
        for(int i=0;i<s.length();i++)
        {
           
            if(s[i]==a)
            {
                lasta = i;
                f1++;
            }
            else if(s[i]==b)
            {
                lastb=i;
                f2++;
            }
            
            if(i >= k-1)
            {
                if(f1%2==1 && f2%2==0 &&  f2 > 0)
                ans = max(ans,f1-f2);
                //we can subtract older ones
                //depending on f1, f2 we have 4 cases to find maxima

                int actual_last = min(lasta,lastb); //we can remove till before idx actual_last
                int sub=INT_MAX;
                if(actual_last >= 0) 
                sub = dp[min(i-k+1,actual_last)][1-f1%2][f2%2];
                
                if(sub != INT_MAX)
                {
                    ans = max(ans,f1-f2 - sub);
                }
                
            }
            
            for(int j=0;j<2;j++)
            for(int t=0;t<2;t++)
            dp[i+1][j][t] = dp[i][j][t];

            dp[i+1][f1%2][f2%2] = min(f1-f2,dp[i+1][f1%2][f2%2]);

        }

        return ans;

    }
    int maxDifference(string s, int k) {
        
        int ans=INT_MIN;
        vector<int>pres(5,0);
        for(int i=0;i<s.length();i++)
        pres[s[i]-'0']=1;
    
        for(char i = '0';i<='4';i++)
        {
            for(char j = '0';j<='4';j++)
            {
                if(i!=j && pres[i-'0']==1 && pres[j-'0']==1)
                ans = max(ans,solve(s,i,j,k));
            }
        }
       
        return ans;
        
    }
};