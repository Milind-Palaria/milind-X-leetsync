class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
      int x=0;
        for(string ele : operations){
          if(ele[0]=='+' || ele[ele.size()-1]=='+'){
            x++;
          }
          else {
            x--;
          }
        }
        return x;
    }
};