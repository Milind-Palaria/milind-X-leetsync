class Solution {
public:
    std::string newString(const std::string& input) {
        std::string result;

        for (char c : input) {
            char newc = c;

            if (newc == 'z') newc = 97;
            else newc++;

            result.push_back(newc);
        }

        return result;
    }

    char kthCharacter(int k) {
        std::string start = "a";

        while (start.size() < k) {
            start += newString(start);
        }

        return start[k-1];
    }
};