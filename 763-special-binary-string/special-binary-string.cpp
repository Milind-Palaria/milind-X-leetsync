#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

class Solution {
public:
    std::string makeLargestSpecial(std::string S) {
        std::vector<std::string> primitives;
        int balance = 0;
        int start = 0;

        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '1') {
                balance++;
            } else {
                balance--;
            }

            // When balance becomes 0, a complete, primitive special substring is found
            if (balance == 0) {
                // The primitive is "1" + makeLargestSpecial(interior) + "0"
                // The interior is from start + 1 to i - start - 1
                std::string interior = S.substr(start + 1, i - start - 1);
                std::string sub = "1" + makeLargestSpecial(interior) + "0";
                primitives.push_back(sub);
                start = i + 1; // Move the start to the next position
            }
        }

        // Sort the primitives in descending order to get the lexicographically largest sequence
        std::sort(primitives.begin(), primitives.end(), std::greater<std::string>());

        // Concatenate the sorted primitives
        std::string result = "";
        for (const std::string& p : primitives) {
            result += p;
        }

        return result;
    }
};