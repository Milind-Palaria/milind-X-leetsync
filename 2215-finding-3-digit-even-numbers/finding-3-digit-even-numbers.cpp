class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>v;
        int n=digits.size();
        for(int i=100;i<1000;i++){
            if(i % 2 == 1) continue; // skip odd numbers

            vector<int> mp(10, 0);   // frequency of digits in current number
            int temp = i;
            while(temp > 0){
                int rem = temp % 10;
                mp[rem]++;
                temp /= 10;
            }

            // Subtract frequency of input digits
            for(int num : digits){
                mp[num]--;
            }

            bool flag = false;
            for(int j = 0; j < 10; j++){
                if(mp[j] > 0){
                    flag = true; // need more of digit j than available
                    break;
                }
            }

            if(!flag){
                v.push_back(i);
            }
        }
        return v;
    }
};