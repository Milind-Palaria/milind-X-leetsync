class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans=target[0];
        int prev=target[0];
        for(int i=1; i<target.size(); i++){
            if(prev>=target[i]){
                prev=target[i];
                continue;
            }
            else{
                ans+=target[i]-target[i-1];
                prev=target[i];
            }
        }
        return ans;
    }
};