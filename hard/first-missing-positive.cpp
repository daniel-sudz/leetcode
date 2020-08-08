using namespace std; 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // add extra space to prevent overflow 
        nums.push_back(0); 
        // remove negs and get smallest int
        int smallest = INT_MAX;
        int largest = INT_MIN;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] > 0) {
                smallest = min(smallest, nums[i]);
            }
            largest = max(largest, nums[i]);
            if (nums[i] <= 0)
                nums[i] = 1; 
        }
        // handle edge cases
        if (largest <= 0)
            return 1;
        if (smallest > 1)
            return 1;
        if (smallest <= 0)
            smallest = 1;
        // normalize so that smallest int is 1
        for (int i = 0; i < nums.size(); i ++) {
            nums[i] -= (smallest - 1);
        }
        // negate positive positions
        for (int i = 0; i < nums.size(); i ++) {
            if (abs(nums[i]) < nums.size() && nums[abs(nums[i])] > 0) {
                nums[abs(nums[i])] *= -1; 
            }
        }
        // verify numbers 1 -> nums.size() are present
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] > 0)
                return (i + smallest - 1);  
        }
        return nums.size();
    }
};
