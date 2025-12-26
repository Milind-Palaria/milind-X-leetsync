class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int penalty = count(begin(customers),end(customers),'Y');
        int minP = penalty;
        int minH = 0;
        for(int i = 0; i < n; i++){
            if(customers[i] == 'Y'){
                penalty--;
            }else{
                penalty++;
            }
            if( penalty < minP){
                minP = penalty;
                minH = i + 1;
            }
        }
        return minH;
    }
};