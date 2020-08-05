using namespace std; 
class Solution {
public:
    vector<string> solutions;
    vector<string> generateParenthesis(int n) {
    recurse(n, n, 0, ""); 
    return solutions; 
    }
    
    void recurse(int openleft, int closedleft, int stack, string partial){
        if (openleft == 0 && closedleft == 0 && stack == 0) {
            solutions.push_back(partial);
            return; 
        }
        if (openleft > 0) {
            recurse(openleft -1, closedleft, stack + 1,  partial + '(');
        }
        if (closedleft > 0 && stack > 0) {
                recurse(openleft, closedleft -1, stack -1, partial + ')');
        }
    }
};
