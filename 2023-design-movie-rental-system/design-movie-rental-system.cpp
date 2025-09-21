#include<bits/stdc++.h>
using namespace std;


class MovieRentingSystem {
public:
    unordered_map<int,unordered_map<int,int>> priceMap;
    unordered_map<int,set<pair<int,int>>> unrented;
    set<tuple<int,int,int>> rented;

    
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &e:entries){
            int shop = e[0],movie = e[1],price = e[2];
            priceMap[shop][movie] = price;
            unrented[movie].insert({price,shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        if(unrented.count(movie)){
            auto it = unrented[movie].begin();
            for(int i=0;i<5 && it!= unrented[movie].end(); i++,++it){
                ans.push_back(it->second);
            }
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = priceMap[shop][movie];
        unrented[movie].erase({price,shop});
        rented.insert({price,shop,movie});
    }
    
    void drop(int shop, int movie) {
        int price = priceMap[shop][movie];
        rented.erase({price,shop,movie});
        unrented[movie].insert({price,shop});
    }
    
    vector<vector<int>> report() {
       vector<vector<int>> ans;
       auto it = rented.begin();
       for(int i=0; i<5 && it != rented.end(); i++,++it){
            ans.push_back({get<1>(*it), get<2>(*it)});
       }
       return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */