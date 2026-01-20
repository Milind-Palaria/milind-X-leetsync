class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        string temp;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==2)
            ans.push_back(-1);
            else
            {
            temp=bitset<32>(nums[i]).to_string();

            for(int i=31;i>=0;i--)
            {
                if(temp[i]=='0' && i+1<32)
                {temp[i+1]='0';
                break;}


            }

            int num=stoi(temp, nullptr, 2);
            ans.push_back(num);
            }
        }

        return ans;
    }
};