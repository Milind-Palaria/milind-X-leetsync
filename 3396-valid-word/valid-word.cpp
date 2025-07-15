class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) return false;

    bool hasVowel = false;
    bool hasConsonant = false;

    for (char ch : word) {
        if (!std::isalnum(ch)) return false;

        if (std::isalpha(ch)) {
            char lowerCh = std::tolower(ch);
            if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
                hasVowel = true;
            } else {
                hasConsonant = true;
            }
        }
    }

    return hasVowel && hasConsonant;
    }
};