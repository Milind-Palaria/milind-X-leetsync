class Solution {
public:

    bool isValid(long long mid, vector<int>& ranks, int cars) {
        long long count = 0;
        for (int i : ranks) {
            if (i == 0) continue; // Prevent division by zero
            long long possible_cars = sqrt(mid / i);
            count += possible_cars;
            if (count >= cars) return true; 
        }
        return count >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        
      //if it is binary search then we have to decide a range
      //max element *n^2 to min element


      unsigned long long high=*max_element(ranks.begin(),ranks.end()) *(long long)cars*cars;   //pow
      long long low=1;

      while(low<high){

        long long mid=low+(high-low)/2;

        if(isValid(mid,ranks,cars)){
            high=mid;
        }
        else{
            low=mid+1;
        }
      }

    return high;
    }
};