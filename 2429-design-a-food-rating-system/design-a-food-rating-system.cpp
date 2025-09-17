class FoodRatings {
public:
    struct Comp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first != b.first) return a.first < b.first; 
            return a.second > b.second;                       
        }
    };

    unordered_map<string, priority_queue<pair<int,string>, vector<pair<int,string>>, Comp>> cuisineToFood;
    unordered_map<string,pair<int,string>>foodRatingCuisine;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0 ; i<foods.size() ; i++){
            cuisineToFood[cuisines[i]].push({ratings[i], foods[i]});
            foodRatingCuisine[foods[i]] = {ratings[i], cuisines[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        foodRatingCuisine[food].first = newRating;
        cuisineToFood[foodRatingCuisine[food].second].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
        while(!cuisineToFood[cuisine].empty() && foodRatingCuisine[cuisineToFood[cuisine].top().second].first != cuisineToFood[cuisine].top().first){
            cuisineToFood[cuisine].pop();
        }
        return cuisineToFood[cuisine].top().second;
    }
};
