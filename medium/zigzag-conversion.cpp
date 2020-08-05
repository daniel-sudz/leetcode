class Solution {
public:
   string convert(string s, int numRows) {
       if (numRows == 1) {
           return s; 
       }
        string* result;
        result = new string[numRows];
        int cur_count = 0;
        int total_count = 0;
        bool is_reg = true;
        for (int i = 0; i < s.size(); i++) {
            if (is_reg == true) {
                result[cur_count] += s[total_count];
                total_count++;
                cur_count++;
                if (cur_count == numRows - 1) {
                    is_reg = false;
                    continue;
                }
            }
            if (is_reg == false) {
                result[cur_count] += s[total_count];
                total_count++;
                cur_count--;
                if (cur_count == 0) {
                    is_reg = true;
                }
            }
        }
        string res_string;
        for (int i = 0; i < numRows; i++) {
            res_string += result[i];
        }
        return res_string;
    }
};
