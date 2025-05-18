#define ll long long

class Solution {
public:

    vector<vector<int>> store;

    ll mod = 1e9+7;

    void solve(int m, int currIndex, int prev, vector<int>& temp){
        if(currIndex==m){
            store.push_back(temp);
            return;
        }

        if(prev==0){
            temp.push_back(1);
            solve(m, currIndex+1, 1, temp);
            temp.pop_back();

            temp.push_back(2);
            solve(m, currIndex+1, 2, temp);
            temp.pop_back();
        }

        if(prev==1){
            temp.push_back(0);
            solve(m, currIndex+1, 0, temp);
            temp.pop_back();

            temp.push_back(2);
            solve(m, currIndex+1, 2, temp);
            temp.pop_back();
        }

        if(prev==2){
            temp.push_back(1);
            solve(m, currIndex+1, 1, temp);
            temp.pop_back();

            temp.push_back(0);
            solve(m, currIndex+1, 0, temp);
            temp.pop_back();
        }

        return;
    }


    bool canBeAdjacent(int i, int j){
        int count=0;
        vector<int> a=store[i], b=store[j];

        for(int i=0; i<a.size(); i++){
            if(a[i]==b[i]){count++;}
        }

        return count==0;
    }

    int colorTheGrid(int m, int n) {
        vector<int> temp;

        temp.push_back(0);
        solve(m, 1, 0, temp);
        temp.pop_back();

        temp.push_back(1);
        solve(m, 1, 1, temp);
        temp.pop_back();

        temp.push_back(2);
        solve(m, 1, 2, temp);
        temp.pop_back();

        unordered_map<int,vector<int>> adj;
        for(int i=0; i<store.size(); i++){
            for(int j=i+1; j<store.size(); j++){
                if(canBeAdjacent(i, j)){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<vector<int>> dp(n+1, vector<int>(store.size()+1, 0));
        for(int i=0; i<store.size(); i++){
            dp[1][i]=1;
        }

        for(int length=2; length<=n; length++){
            for(int index=0; index<store.size(); index++){
                vector<int> adjacency = adj[index];
                ll tempAns = 0;
                for(auto i: adjacency){
                    tempAns = (tempAns + (ll)(dp[length-1][i]))%mod;
                }
                tempAns = tempAns%mod;
                dp[length][index] = (int)tempAns;
            }
        }

        ll ans = 0;
        for(int i=0; i<store.size(); i++){
            ans = (ans + (ll)(dp[n][i]))%mod;
        }

        return (int)ans;
    }
};