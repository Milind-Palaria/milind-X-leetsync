class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> arr(n);
        int i = 0;
        int ele = 1;
        while(i+1 < n){
            arr[i] = ele;
            arr[i+1] = -ele;
            i += 2;
            ele++;
        }
        return arr;
    }
};