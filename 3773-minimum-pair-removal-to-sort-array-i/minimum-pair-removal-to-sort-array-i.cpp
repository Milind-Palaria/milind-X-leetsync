using namespace std;
#include <iostream>
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        bool increasing=false;
        int counter=0;
        while(!increasing){
            increasing=true;
            vector<int> sums;
            for (int i = 0; i+1 < nums.size(); i++) {
                int prev=nums[i];
                int next=nums[i+1];
                if(prev>next){
                    increasing=false;
                }
                sums.push_back(prev + next);
            }
            
            if(increasing==false){
                auto min_value=*min_element(sums.begin(), sums.end());
                auto it=find(sums.begin(), sums.end(), min_value);
                int idx1=it - sums.begin();
                nums[idx1] = min_value;
                nums.erase(nums.begin() + idx1 + 1);
                counter++;
                }

        }
        return counter;

    }
};