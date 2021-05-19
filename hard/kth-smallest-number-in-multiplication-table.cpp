class Solution {
public:
    // optimally it could be 
    // O(min(m,n) * log(m * n))
    int check(int m, int n, int val, int k) {
        int lessThan = 0; 
        int equalTo = 0; 
        // find amount less than in each row
        for (int i = 1; i <= n; i ++) {
            int loc = val / i;
            if (loc != 0) {
                // outside of bounds
                if (loc > m) {
                    lessThan += m;
                }
                // remainder from division
                else if (loc * i < val) {
                    lessThan += loc; 
                }
                // no remainder
                else {
                    lessThan += loc - 1;
                    equalTo ++; 
                }
            }

        }
        if (lessThan >= k) {
            return 1; // high
        }
        if (lessThan + equalTo < k) {
            return 0; // low
        }
        return 2; // valid
    }
    int findKthNumber(int m, int n, int k) {
        // speedup to reverse indexing by min(n,m) instead of just n
        if (m < n) {
            int tmp = n; 
            n = m; m = tmp; 
        }
        int low = 0; 
        int high = m * n + 1; 
        while (low + 1 < high) {
            int mid = (low + high) / 2; 
            int comp = check(m, n, mid, k); 
            if (comp == 1) {
                high = mid - 1; // exclusive
            }
            else {
                low = mid; // inclusive
            }
        }
        if (check(m,n,low,k) == 2) return low; 
        return low + 1; 
    }
};

/** 
BruteForce: O(m*n * log(m + n))
        multiset<int, less<int>> nums;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                nums.insert((i + 1) * (j + 1));
            }
        }
        auto it = nums.begin(); 
        advance(it, k - 1); 
        return *it;
**/
