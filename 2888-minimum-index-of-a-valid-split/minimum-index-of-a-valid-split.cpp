class Solution {
public:
    int minimumIndex(vector<int>& nums) {

        unordered_map<int, int> freq;

        int dominator =0;
        int count =0;
        int n = nums.size();

        for(auto ele : nums){
            freq[ele]++;
        }

        for(auto [ele, c]: freq){
            if(c>n/2 ){
                dominator = ele;
                count = c;
                break;
            }
        }

        int leftcount =0;
        for( int i =0; i< n-1; i++){
            if(nums[i] == dominator){
                leftcount++;
            }
            int leftSize= i+1;
            int rightSize = n- leftSize;
            int rightcount = count -leftcount;

            if(leftcount > leftSize/2 && rightcount > rightSize/2){
                return i;
            }

        }
        return -1;




        
    }
};