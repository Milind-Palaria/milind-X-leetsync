class Router {
public:
    
    int n;
    deque<vector<int>>v1;
    map<vector<int>,int>m1;
    map<int,vector<int>>dst;

    Router(int mL) {
        n=mL;
    }


    void addd(vector<int>&nums,int kk){
        if(nums.size()==0){
            nums.push_back(kk);
        }
        else{
            int l=0;
            int h=nums.size()-1;

            int ans = nums.size();

            while(l<=h){
                int mid=(l+h)/2;

                if(nums[mid]>=kk){
                    h=mid-1;
                    ans=mid;
                }
                else{
                   l=mid+1;
                }
            }


            nums.insert(nums.begin()+ans,kk);

        }
    }

    void dell(vector<int>&nums,int kk){
        int l=0;
        int h=nums.size()-1;

        while(l<=h){
            int mid=(l+h)/2;

            if(nums[mid]==kk){
                nums.erase(nums.begin()+mid);
                break;
            }

            if(nums[mid]>kk){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
    }
    
    bool addPacket(int s, int d, int t) {
        if(m1.find({s,d,t})!=m1.end()) return 0;

        if(v1.size()+1>n){
            vector<int>nums=v1.front();
            v1.pop_front();
            m1.erase(nums);
            dell(dst[nums[1]],nums[2]);
        }


        m1[{s,d,t}]++;
        v1.push_back({s,d,t});
        addd(dst[d],t);

        return 1;
    }
    
    vector<int> forwardPacket() {
        if(v1.size()==0) return {};

        vector<int>nums=v1.front();
        v1.pop_front();
        m1.erase(nums);
        dell(dst[nums[1]],nums[2]);

        return nums;
    }
    
    int getCount(int d, int s, int e) {
        

        auto it1 = lower_bound(dst[d].begin(), dst[d].end(), s);     
        auto it2 = upper_bound(dst[d].begin(), dst[d].end(), e);     
        return static_cast<int>(it2 - it1);
        
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */