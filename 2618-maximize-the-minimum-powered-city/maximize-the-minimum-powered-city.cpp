class Solution {
private:
    long long dat[100005];
    long long prefix[100005];
    long long p[100005];
    int n;

    bool check(long long val, int r, int k){
        long long temp = 0, ret = 0;
        for (int i = 0; i <= n; i++){
            p[i] = 0;
        }

        for (int i = 0; i < n; i++){
            temp += p[i];
            if (dat[i] + temp < val){
                ret += (val - temp - dat[i]);
                p[min(n, i + r + r + 1)] -= (val - temp - dat[i]);
                temp = val - dat[i];
            }
        }
        return (ret <= k);
    }
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        prefix[0] = 0;
        n = stations.size();
        for (int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + stations[i];
        }
        for (int i = 0; i < n; i++){
            dat[i] = prefix[min(n, i + r + 1)] - prefix[max(0, i - r)];
        }

        long long left = 0, right = 1e11, mid, ret = 0;

        while (left <= right){
            mid = (left + right) >> 1;
            if (check(mid, r, k)){
                left = mid + 1;
                ret = mid;
            }
            else{
                right = mid - 1;
            }
        }
        return ret;
    }
};