using namespace std; 
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool first_word_cap = isupper(word[0]);
        if (word.size() == 1) 
            return true; 
        bool second_word_cap = isupper(word[1]);
        
        for (int i = 1; i < word.size(); i ++) {
                if (first_word_cap && second_word_cap && !isupper(word[i]))
                    return false; 
                if (first_word_cap &&!second_word_cap && isupper(word[i]))
                    return false; 
                if (!first_word_cap && isupper(word[i]))
                    return false; 
            }
        return true; 
        }
};
