#define ll long long
class Solution {
    unordered_map<int, int> map;  // keeping count of usage of a room
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;    
// min heap to store endtime of a room and room number
    priority_queue<int, vector<int>, greater<int>> pqq; // min heap to store available rooms
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end()); // sort so meetings are arranged with increasing start times
        for(int i=0; i<n; i++) pqq.push(i);
        for(int i=0; i<meetings.size(); i++) {
            long long start= meetings[i][0];
            long long end= meetings[i][1];
            long long duration= end- start;
            if(!pqq.empty()) {
                //rooms are available now
                while(!pq.empty()) {
                    if(pq.top().first <= start) {
                        pqq.push(pq.top().second);
                        pq.pop();
// take away those rooms whose meetings have ended on or before startTime
                    }
                    else break;
                }
                int room= pqq.top();
                pqq.pop();
                pq.push({end, room});
                cout<<end<<" "<<room<<endl;
                map[room]++;
// room available so start the meeting
            }
            else {
                if(pq.top().first >= start) {
                    //meeting will be delayed as all rooms are busy
                    long long newstart= pq.top().first;
                    int room= pq.top().second;
                    pq.pop();
                    pq.push({newstart+duration, room});
// fixing new start time
                    cout<<newstart+end-start<<" "<<room<<endl;
                    map[room]++;
                }
                else {
                    //meeting by default is late scheduled so just clean all records upto the case when meeting can be still scheduled on time i.e. in order to get lowest possible room number from those rooms whose meeting will end before this one's start time.
                    while(!pq.empty()) {
                        if(pq.top().first <= start) {
                            pqq.push(pq.top().second);
                            pq.pop();
                        }
                        else break;
                    }
                    int room= pqq.top();
                    pqq.pop();
                    pq.push({end, room});
                    cout<<end<<" "<<room<<endl;
                    map[room]++;
                }
            }
        }
        int maxroom= -1;
        int maxfreq= 0;
        for(int i=0; i<n; i++) {
            int freq= map[i];
            cout<<"room: "<<i<<" freq: "<<freq<<endl;
            if(freq>maxfreq) { maxroom= i; maxfreq= freq; }
//simple comparison for final answer, i hope u won't get stuck here :)
        }
        return maxroom;
    }
};