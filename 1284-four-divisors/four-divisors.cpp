class Solution {
public:
        int divisor(int temp){
            
            int count = 0;
            int sum = 0;

            for (int i = 1; i * i <= temp; i++) {
                if (temp % i == 0) {
                    int d1 = i;
                    int d2 = temp / i;

                    if (d1 == d2) {
                        count++;
                        sum += d1;
                    } else {
                        count += 2;
                        sum += d1 + d2;
                    }
                }

                if (count > 4) return 0;
            }

            if (count == 4) return sum;
            return 0;
        }

    int sumFourDivisors(vector<int>& nums) {
         int isdivisor = 0;
        for(int i = 0; i < nums.size(); i++){
            int temp = nums[i];
             isdivisor += divisor(temp);

        }
        return isdivisor;
    }
};