class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        return searchpivot(0, nums.size() / 2, nums.size() - 1, nums, target);
    }

    int searchpivot(int low, int med, int high, vector<int>& nums, int target) {
        if (nums[low] == target)
            return low; 
        if (nums[med] == target)
            return med; 
        if (nums[high] == target)
            return high; 
        // pivot is not between med/high exclusive
        if (nums[high] >= nums[med]) {
            // pivot is not between med/high exclusive and med<=target<=high
            if (target >= nums[med] && target <= nums[high]) {
                if (low == med && (med + high) / 2 == med) {
                    return -1; 
                }
                return searchpivot(med, (med + high) / 2, high, nums, target);
            }
            //pivot is not between med/high exclusive and target <= low
            else {
                if (med == high && (low + med) / 2 == med) {
                    return -1;
                }
                return searchpivot(low, (low + med) / 2, med, nums, target);
            }
        }
        // pivot is not between low and med exclusive
        else if (nums[low] <= nums[med]) {
            // pivot is not between low and med exclusive and low<=target<=med
            if (target >= nums[low] && target <= nums[med]) {
                if (med == high && (low + med) / 2 == med) {
                    return -1;
                }
                return searchpivot(low, (low + med) / 2, med, nums, target);
            }
            // pivot is not between low/med exclusive and target >= med
            else {
                if (low == med && (med + high) / 2 == med) {
                    return -1;
                }
                return searchpivot(med, (med + high) / 2, high, nums, target);
            }
        }
        return -1;
    }
};
