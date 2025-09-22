class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> freq;
        sort(nums.begin(),nums.end());
        int f=1,a=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==a){
                f++;
            }
            else{
                freq.push_back(f);
                f=1;
                a=nums[i];
            }
        }
        freq.push_back(f);
            sort(freq.begin(),freq.end(),greater<int>());
            int nn=freq.size();
            int fa=freq[0];
           int st=0;
           if(nn==1){
            return fa;
           }
           else{
            while(freq[st]==freq[st+1]){
                
                fa=fa+freq[st+1];
                st++;
                if(st==nn-1){
                    break;
                }
                
            }
           }
return fa;
    }
};