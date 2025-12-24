class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n= events.size();
        vector<pair<int,int>>arr;
        int mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int start= events[i][0];
            int val= events[i][2];
            arr.push_back({start,val});
        }
        sort(arr.begin(),arr.end());
        vector<int>maximum(n,0);
        for(int i=n-1;i>=0;i--)
        {
            mx= max(mx,arr[i].second);
            maximum[i]= mx;
        }
        for(int i=0;i<n;i++)
        {
            int val=events[i][2];
            int end= events[i][1];
            auto it= upper_bound(arr.begin(),arr.end(),make_pair(end,INT_MAX));
            if(it!=arr.end())
            {
                int ind= it-arr.begin();
                mx= max(mx,(val+maximum[ind]));
            }
        }
        return mx;
    }
};