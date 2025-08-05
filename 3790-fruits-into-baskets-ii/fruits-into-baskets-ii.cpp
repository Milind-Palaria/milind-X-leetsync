class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& basket) {
        int n = basket.size();
        vector<bool> vis(n, false);
        int count = 0;

        for(int i=0; i<fruits.size(); i++){
            for(int j=0; j<n; j++){

                if(fruits[i] <= basket[j] && !vis[j]){
                    vis[j] = true;
                    count++;
                    break;
                }
            }
        }
        return n - count;
    }
};