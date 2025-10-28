class Solution {
public:

    int countValidSelections(vector<int>& nums) {
        int left = 0;
        int right = 0;
        for(int num: nums) right += num;
        int rc = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums.at(i) == 0) {
                if(right == left) rc += 2;
                else if(abs(right - left) == 1) rc += 1;
            }
            else {
                right -= nums.at(i);
                left += nums.at(i);
            }
        }

        return rc;
    }
};