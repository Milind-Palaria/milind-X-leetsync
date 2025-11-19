class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> st;
        for(int n : nums){
            st.insert(n);
        }
        while(st.count(original)){
            original*=2;
        }
        return original;
    }
};