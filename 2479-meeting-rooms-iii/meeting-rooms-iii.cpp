class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        map<int, int> mp;
        int m = meetings.size();
        priority_queue<pair<long long ,long long int>, vector<pair<long long int,long long int>>, greater<pair<long long int,long long int>>> pq;
    
        sort(meetings.begin(), meetings.end());
        
        for(int i = 0; i < n; i ++) {
            pq.push({0, i});
        }

        int i = 0;
        while(i < m ){
            while(meetings[i][0]>pq.top().first){
                long long int room = pq.top().second;
                long long int time = pq.top().first;
                pq.pop();
                pq.push({meetings[i][0],room});

            }
            long long int room = pq.top().second;
            long long int time = pq.top().first;
            pq.pop();
            pq.push({time + meetings[i][1] - meetings[i][0],room});
            mp[room]++;
            i++;
            
        }

        int ans = 0 ;
        int meets = 0;
        for(auto i : mp){
            if(i.second > meets){
                ans = i.first;
                meets = i.second;
            }
        }
        return ans;

    }
};