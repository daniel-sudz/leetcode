using namespace std; 
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false; 
        long x_org = (long) x; 
        long ret = 0;
        while (x != 0) {
            ret = ret*10 + x%10; 
            x/=10; 
        }
        if (x_org == ret)
            return true; 
        return false; 
    }
};
