class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int cnt = 0;int m = capacity.size();
       int appleSum = accumulate(apple.begin(), apple.end(), 0);
        int capacitySum=0;
        sort(capacity.begin(),capacity.end());
        for(int i=m-1;i>=0;i--){
            capacitySum+=capacity[i];
                cnt++;
            if(appleSum-capacitySum<=0){
                break;
            }
        }
        return cnt;
    }
};