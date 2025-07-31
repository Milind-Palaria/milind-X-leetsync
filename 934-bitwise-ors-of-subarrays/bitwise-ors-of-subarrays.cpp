class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>myset;
        unordered_set<int>prev;
       
        int n = arr.size();
        for(int i=0;i<n;i++){
             unordered_set<int>curr;
            for(const int& x:prev){
                curr.insert(arr[i]|x);
                myset.insert(arr[i]|x);
            }
            curr.insert(arr[i]);
            prev = curr;
            myset.insert(arr[i]);
        }
        return myset.size();
    }
};