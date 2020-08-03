using namespace std; 
class Solution {
public:
    int reverse(int x) {
        long x_l = (long) x; 
        bool isneg = false; 
        if (x_l < 0) {
            isneg = true; 
            x_l *= -1; 
        }
        long output = 0; 
        int power = getlength(x_l) - 1; 
        
       while (x_l != 0) {
                int digit = x_l % 10; 
                output += ((long) pow(10, power) * digit); 
                power --; 
                x_l /= 10; 
            }
        if (output >= INT_MAX) 
            return 0;
        if (isneg)
            return output * -1;
        return output;
    }
    
    int getlength (int x) {
        int len = 0; 
        while (x != 0) {
            x /= 10; 
            len++;
        }
        return len; 
    }
};

// Solution can be simplied. There is no need to get the length of the number - we can simply multiple by 10 on each digit that is chopped off. 
