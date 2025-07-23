class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int points = 0;
        char ch1 = 'a', ch2 = 'b';
        int cn1 = 0, cn2 = 0;
        if (x < y) {
            swap(x, y);
            ch1 = 'b';
            ch2 = 'a';
        }
        for(char ch:s) {
            if (ch == ch1) {
                cn1++;
            } else if (ch == ch2 ) {
                if (cn1 > 0) {
                    cn1--;
                    points += x;
                } else {
                    cn2++;
                }
            } else {
                points += min(cn1, cn2) * y;
                cn1 = 0;
                cn2 = 0;
            }
        }
        if(cn1 != 0) {
            points += min(cn1, cn2) * y;
        }
        return points;
    }
};