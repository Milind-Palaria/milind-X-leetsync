using ll = long long;

/*
  [1, -3, 4]
[0, 1, -2, 2]
[3, 4, 1, 5]
6 - 5 + 1 => 2
ANS: 2
*/

class Solution {
public:
    int numberOfArrays(vector<int>& diffs, int lower, int upper) {
        int n = diffs.size();
        vector<ll> arr(n + 1, 0);
        int min_index = 0;
        for(int i=0; i<n; i++) {
            arr[i+1] = arr[i] + diffs[i];
            if(arr[min_index] > arr[i+1]) {
                min_index = i + 1;
            }
        }
        int l = min_index - 1, r = min_index + 1;
        arr[min_index] = lower;
        ll max_value = lower;
        while(l >= 0) {
            arr[l] = arr[l + 1] - diffs[l];
            max_value = (arr[l] > max_value ? arr[l] : max_value);
            l--;
        }
        while(r <= n) {
            arr[r] = arr[r - 1] + diffs[r - 1];
            max_value = (arr[r] > max_value ? arr[r] : max_value);
            r++;
        }
        return max(0, int(upper - max_value + 1));
    }
};