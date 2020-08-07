using namespace std; 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return;
        }
        int prev = nums.size() - 1;
        // find first position that needs to be swapped
        for (int i = nums.size() - 1; i >= 0; i --) {
            if (nums[prev] > nums[i]) {
                break; 
            }
            if (nums[i] >= nums[prev])
                prev = i; 
        }
        // return reverse if not possible to swap
        cout << prev - 1 << endl;
        if (prev == 0) {
            reverse(nums.begin(), nums.end());
            return; 
        }
        // find lowest possible swapper
        int lowest = INT_MAX;
        for (int i = nums.size() - 1; i > prev - 1; i --) {
            if (nums[i] > nums[prev - 1]) {
                if (lowest < nums.size() == false) {
                    lowest = i; 
                }
                else if (nums[i] < nums[lowest])  {
                    lowest = i; 
                }
            }
        }
        // swap, reverse, return 
        int temp = nums[prev - 1]; 
        nums[prev -1] = nums[lowest];
        nums [lowest] = temp; 
        reverse(nums.begin() + (prev), nums.end()); 
        return; 
    }
};
