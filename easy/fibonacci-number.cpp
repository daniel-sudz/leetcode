// SLOW SOLUTION
/*
class Solution {
public:
    int fib(int N) {
        if (N == 0) 
            return 0; 
        if (N == 1)
            return 1; 
        return (fib(N-1) + fib(N-2));
    }
};
*/
// MODERATELY FAST
using namespace std; 
class Solution {
public:
    int last1 = 1; 
    int last2 = 0; 
    int it = 1; 
    int fib(int N) {
        if (N == 1) 
            return 1; 
        if (N == 0)
            return 0;
        while (it != N) {
            cout << last1 << last2; 
            int l1t = last1; 
            int l2t = last2; 
            
            last1 = l1t + l2t; 
            last2 = l1t; 
            
            it ++; 
        }
        return last1; 
    }
};
