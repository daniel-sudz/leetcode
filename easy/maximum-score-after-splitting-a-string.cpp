using namespace std;
class Solution {
public:
    int maxScore(string s) {
        int max_score; 
        int int_left_score = 0;
        if (s[0] == '0') {
            int_left_score = 1; 
        }
        int int_right_score = 0;
        for (int i = 1; i < s.length(); i ++) {
            if (s[i] == '1') {
                int_right_score ++; 
            }
        }
        max_score = int_left_score + int_right_score; 
        for (int i = 1; i < s.length() -1 ; i ++) {
            if (s[i] == '0') {
                int_left_score ++; 
            }
            if (s[i] == '1') {
                int_right_score --; 
            }
            max_score = max(max_score, int_left_score + int_right_score); 
        }
        return max_score; 
    }
};

// STATS
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Score After Splitting a String.
// Memory Usage: 6.3 MB, less than 75.41% of C++ online submissions for Maximum Score After Splitting a String.
// Date: August-3-2020
