class Solution {
private:
    struct cmp
    {
        bool operator()(pair<int,int>a,pair<int,int>b)
        {
            if(a.second==b.second)
            return a.first<b.first;

            return a.second<b.second;
        }
    };

    int Xsum(vector<int>&nums,unordered_map<int,int>&mp,int x)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        int sum=0;

        for(auto it:mp)
        {
            cout<<it.first<<" "<<it.second<<endl;
            pair<int,int>p=make_pair(it.first,it.second);
            pq.push(p);
        }

        cout<<endl;

        while(!pq.empty() && x>=1)
        {
            pair<int,int>p=pq.top();
            // cout<<p.first<<" "<<p.second<<endl;
            pq.pop();
            x--;
            sum+=p.first*p.second;
        }

        return sum;
    }

public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {

        vector<int>ans;
        int l=0;
        int r=0;

        unordered_map<int,int>mp;

        while(r<nums.size())
        {
            int len=r-l+1;

            if(len>k)
            {
                mp[nums[l]]--;
                l++;
            }

            mp[nums[r]]++;
            len=r-l+1;

            if(len==k)
            {
                int sum=Xsum(nums,mp,x);
                ans.push_back(sum);
            }

            r++;
        }

        return ans;

    }
};