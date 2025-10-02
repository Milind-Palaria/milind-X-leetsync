class Solution {
public:
    int maxBottlesDrunk(int bottles, int cost) {
        int consumed = bottles;


        while(bottles >=  cost){
            bottles -= (cost - 1);
            cost++;
            consumed++;
        }

        return consumed;
        
    }
};