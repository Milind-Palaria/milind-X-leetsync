class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int first = -1, second = -1;
        int len = fruits.size();
        if(len==1) return 1;
        int mx = 1;
        int cnt = 1;
        int combo = 1;
        first = fruits[0];
        for(int i=1;i<len;i++){
            if(fruits[i]==first) cnt += 1;
            else if(fruits[i]==second || second==-1){
                second = fruits[i];
                cnt+= 1;
            }
            else{
                mx = max(mx,cnt);
                first = fruits[i-1];
                second = fruits[i];
                cnt = combo + 1;
            }
            if(fruits[i]==fruits[i-1]) combo += 1;
            else combo = 1;
        }
        mx = max(mx,cnt);
        return mx;
    }
};