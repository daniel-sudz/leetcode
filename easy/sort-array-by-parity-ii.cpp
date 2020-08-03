using namespace std;
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> ODD_POS_WHICH_IS_EVEN;
        for (int i = 0; i < A.size(); i ++) {
            if (i % 2 == 1 && A[i] % 2 == 0) {
                ODD_POS_WHICH_IS_EVEN.push_back(i);
            }
        }
        int ODD_POS_COUNTER = 0; 
        for (int i = 0; i < A.size(); i ++) {
            if (i % 2 == 0 && A[i] % 2 == 1) {
                int temp = A[i];
                A[i] = A[ODD_POS_WHICH_IS_EVEN[ODD_POS_COUNTER]]; 
                A[ODD_POS_WHICH_IS_EVEN[ODD_POS_COUNTER]] = temp;
                ODD_POS_COUNTER ++; 
            }
        }
        return A; 
    }
};



// Double Pass Solution
