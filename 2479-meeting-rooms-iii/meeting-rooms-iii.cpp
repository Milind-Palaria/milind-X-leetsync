class Solution {
public:
    #define p pair<ll,int>
    #define ll long long int
    int mostBooked(int n, vector<vector<int>>& m) {
        vector<int> c(n,0);
        sort(m.begin(),m.end());
        priority_queue<int, vector<int>, greater<int> >unused;
        priority_queue<p, vector<p>, greater<p>>pq;
        for (int i=0;i<n;i++)
            unused.push(i);
        ll t=0,s=m.size();
        for(int i=0;i<s;i++)
        {
            t=max(t,(ll)m[i][0]);
            while(pq.size()>0 && pq.top().first <= t)
            {
                unused.push(pq.top().second);
                pq.pop();
            }
            if(unused.size()==0)
            {
                unused.push(pq.top().second);
                t=pq.top().first;
                pq.pop();
            }
            ll d = m[i][1]-m[i][0];
            int r = unused.top();
            c[r]++;
            unused.pop();
            pq.push({t+d, r});
        }
        int res=0,x=0;
        for(int i=0;i<n;i++)
        {
            if(c[i]>x)
            {
                x=c[i];
                res=i;
            }
        }
        return res;
    }
};