using namespace std; 
class Solution {
public:
    bool isValid(string s) {
        vector<char> stack; 
        
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '(')
                stack.push_back('(');
            if (s[i] == '{')
                stack.push_back('{');
            if (s[i] == '[')
                stack.push_back('[');

            if (s[i] == ')') {
                if (stack.size() > 0 && stack[stack.size() -1] == '(')
                    stack.pop_back();
                else 
                    return false; 
            }
            if (s[i] == '}') {
                if (stack.size() > 0 && stack[stack.size() -1] == '{')
                    stack.pop_back();
                else 
                    return false; 
            }
            if (s[i] == ']') {
                if (stack.size() > 0 && stack[stack.size() -1] == '[')
                    stack.pop_back();
                else 
                    return false; 
            }
        } 
        if (stack.size() == 0) {
            return true;
        }
        return false; 
    }
};
