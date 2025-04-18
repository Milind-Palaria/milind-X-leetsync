class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        string prev = s;

        for (int i = 1; i < n; i++) {

            string curr = "";
            int count = 0;
            char temp = prev[0];
            for (char x : prev) {
                if (x == temp) count++;
                else {
                    //temp = x;
                    curr.push_back('0'+count);
                    curr.push_back(temp);
                    temp = x;
                    count = 1;
                }
            }
            curr.push_back('0'+count);
            curr.push_back(temp);
            prev = curr;

        }
        return prev;
    }
};