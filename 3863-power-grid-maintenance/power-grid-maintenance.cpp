class Disjoint{
    public:
    vector<int> parent;
    Disjoint(int n){
        parent.resize(n);
        parent[0] = 0;
        for( int i = 1; i < n; i++) parent[i] = i;
    }

    int find(int x){

        if( parent[x] == x) return x;

        return parent[x] = find(parent[x]);
    }

    void unionSet(int u , int v){

        int p_u = find(u);
        int p_v = find(v);
        if(p_u == p_v) return;
        if( p_u < p_v){
            parent[p_v] = p_u;
        }
        else{
            parent[p_u] = p_v;
        }
    }
};



class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {

        vector<bool> active(c + 1, true);
        Disjoint ds(c+1);


        for( auto it : connections){
            int u = it[0];
            int v = it[1];
            ds.unionSet(u , v);
        }

        unordered_map<int,set<int>> comp;
        for( int i = 1; i <= c; i++){
            int par = ds.find(i);
            comp[par].insert(i);
        }

        vector<int> result;
        for( auto it : queries){

            int type = it[0];
            int node = it[1];
            int par = ds.find(node);

            if(type == 1){

                int res = node;
                if(!active[node]) {

                    if(!active[par]) {
                        for(auto it : comp[par]){

                            if(active[it]) {
                                res = it;
                                break;
                            }
                        }
                        if(res == node ) res = -1;
                    }
                    else res = par;
                    
                }

                result.push_back(res);

            }else{
                active[node] = false;
                if( comp[par].find(node) != comp[par].end()) comp[par].erase(node);
            }
        }

        return result;
    }
};  