class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        int n = answers.size();
        int sum = 0;

        for(int i=0; i<n; i++){
            if(answers[i] == 0) sum++;
            else mp[answers[i]]++;
        }

        for(auto it : mp){
            if(it.first + 1 == it.second){
                sum += it.second;
            }
            else{
                int temp = it.second;
                cout<<it.first<<" "<<it.second<<endl;
                while(temp > 0){
                    temp -= it.first + 1;
                    sum += it.first + 1;
                }
            }
        }

        return sum;
    }
};