using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        if (strs.size() == 0)
            return "";
        int min_length = strs[0].size(); 
        
        for (int i = 0; i < strs.size(); i ++) {
            min_length = min<int>(min_length, strs[i].size());
        }
        
        for (int i = 0; i < min_length; i ++) {
            char first_char = strs[0][i]; 
            for (int b = 0; b < strs.size(); b ++) {
                if (strs[b][i] != first_char)
                    return prefix;  
            }
            prefix += first_char; 

        }
        return prefix; 
    }
};
