class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int person = languages.size();

        vector<unordered_set<int>> person_languages(person+1);
        for(int i=0; i<person; i++){
            for(int lang : languages[i]){
                person_languages[i+1].insert(lang);
            }
        }

        unordered_set<int> sad_users;

        for(auto &group : friendships){
            int u = group[0];
            int v = group[1];

            bool canCommunicate = false;
            for(int lang : person_languages[u]){
                if(person_languages[v].count(lang)){
                    canCommunicate = true;
                    break;
                }
            }
            if(!canCommunicate){
                sad_users.insert(u);
                sad_users.insert(v);
            }
        }

        vector<int> most_lang(n+1, 0);
        int most = 0;
        for(int user : sad_users){
            for(int lang : person_languages[user]){
                most_lang[lang]++;
                most = max(most, most_lang[lang]);
            }
        }

        return sad_users.size() - most;
    }
};