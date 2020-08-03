using namespace std; 
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) {
            return false; 
        }
        int sum_factor = 1; 
        for (int i = 2; i < ceil(sqrt(num)); i ++) {
            if (num % i == 0) {
                sum_factor += i; 
                if (num/i != i) {
                    sum_factor += (num/i); 
                }
            }
        }
        if (sum_factor == num) {
            return true;
        }
        return false; 
    }
};
