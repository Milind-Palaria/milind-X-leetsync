class Solution {
public:
    string clearStars(string s) {
        vector < vector<int>> nums(26);
        for(int i =0; s[i] ; i++){
            if(s[i] == '*'){
                for(int j = 0 ; j<26 ; j++){
                    if(nums[j].size()){
                        s[nums[j].back()] = '*';
                        nums[j].pop_back();
                        break;
                    }
                }
            }else nums[s[i]-'a'].push_back(i);
        }

        string ans ;
        for(auto it : s){
            if(it!='*'){
                ans.push_back(it);
            }
        }
        return ans;
    }
};
