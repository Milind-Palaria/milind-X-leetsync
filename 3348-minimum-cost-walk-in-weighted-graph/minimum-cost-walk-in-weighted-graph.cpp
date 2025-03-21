class Solution {
public:


    bool buildConnectedVertices(int begin, int end, unordered_map<int, vector<pair<int, int>>>& edgeMap, unordered_set<int>& connectedVertices, int& leastVal) {
        leastVal = INT_MAX;
        bool found = false;
        connectedVertices.insert(begin);
        queue<int> line; 
        line.push(begin);

        while(!line.empty()) {
            int current = line.front(); 
            line.pop(); 


            if(edgeMap.find(current) != edgeMap.end() && !edgeMap[current].empty()) {
                for(const pair<int, int>& edge : edgeMap[current]) {
                    int neighbor = edge.first; 
                    int weight = edge.second;

                    leastVal &= weight;

                    if (connectedVertices.find(neighbor) == connectedVertices.end()) {
                        connectedVertices.insert(neighbor);
                        line.push(neighbor);
                      
                        if (neighbor == end)
                            found = true; 
                    }
                }
            }
            
        }

        return found; 
    }


    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> ans = {};
        unordered_map<int, vector<pair<int, int>>> edgeMap; 
        unordered_map<int, pair<int, unordered_set<int>>> islands; 
        int numOfIslands = 0; 
        int numOfEdges = 0;

        for (const auto& edge : edges) {
            edgeMap[edge[0]].push_back({edge[1], edge[2]});
            edgeMap[edge[1]].push_back({edge[0], edge[2]});
            ++numOfEdges; 
        }



        for (const auto& q : query) {            
            
            int leastVal = INT_MAX; 

            if (edgeMap.find(q[0]) == edgeMap.end() || edgeMap.find(q[1]) == edgeMap.end()) {
                ans.push_back(-1);
                continue;
            }
            
            if(numOfEdges == 1) {
                auto it = edgeMap.begin(); 
                auto pair = it->second;
                ans.push_back(pair[0].second);
                continue;
            }
            
            bool isIslandGenerated = false;
            bool qOnSameIsland = false;             
            for (const auto& island : islands) {
                
                const auto& set = island.second; 
                int lValue = set.first; 
                const unordered_set<int>& islandSet = set.second; 
                
                    
                if(islandSet.find(q[0]) != islandSet.end() || islandSet.find(q[1]) != islandSet.end()) {       
                    isIslandGenerated = true; 
                    if(islandSet.find(q[0]) != islandSet.end() && islandSet.find(q[1]) != islandSet.end()) {
                        qOnSameIsland = true; 
                        leastVal = lValue;  
                        break;
                    }
                }
            }
            

            if (isIslandGenerated) {
                if (qOnSameIsland)
                    ans.push_back(leastVal);
                else 
                    ans.push_back(-1);
                continue;
            }
            unordered_set<int> connectedVertices;
            bool pathExists = buildConnectedVertices(q[0], q[1], edgeMap, connectedVertices, leastVal);
            
            if (pathExists) {
                islands[numOfIslands++] = {leastVal, connectedVertices};
            }
            else 
                leastVal = -1;

            
                
            ans.push_back(leastVal);
        }
            
        
        return ans;
    }
};