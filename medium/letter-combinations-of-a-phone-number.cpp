using namespace std; 
class Solution {
public:
      vector<vector<char>> map1 = {{'a','b','c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'}, {'m','n','o'}, {'p','q','r','s'}, {'t','u','v'}, {'w','x','y','z'}}; 
    vector<string> letterCombinations(string digits) {
        if (digits == "") 
            return vector<string>{};
        reverse(digits.begin(), digits.end()); 
        recurse("", stoi(digits)); 
        return solutions; 

    }
    vector<string> solutions; 
    void recurse(string partial, int digitspartial) {
        if (digitspartial == 0) {
            solutions.push_back(partial); 
            return;
        }
        if (digitspartial % 10 == 7 || digitspartial % 10 == 9){
            recurse(partial + map1[digitspartial%10 - 2][3], digitspartial/10);
        }
        recurse(partial + map1[digitspartial%10 - 2][0], digitspartial/10);
        recurse(partial + map1[digitspartial%10 - 2][1], digitspartial/10);
        recurse(partial + map1[digitspartial%10 - 2][2], digitspartial/10);
    }
};
