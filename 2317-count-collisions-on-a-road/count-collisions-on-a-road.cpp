class Solution {
public:
    int countCollisions(string directions) {
        int l_count = 0;
        int r_count = 0;
        int s_count = 0;
        int total = 0;
        for(int i = 0;i<directions.size();i++){
            char c = directions[i];
            if(c == 'R'){
                r_count++;
            }else if(c == 'S'){
                total += r_count;
                r_count = 0;
                s_count = 1;
            }
            else{
                if(r_count>0){
                    total += 2;
                    total += (r_count-1);
                    r_count = 0;
                    s_count = 1;
                }else{
                    total += s_count;
                }
            }
        }
    return total;
    }
};