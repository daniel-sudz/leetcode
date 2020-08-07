class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target <= nums[0]) {
            return 0;
        }
        if (target == nums[nums.size() -1]) {
            return nums.size() -1; 
        }
        if (target > nums[nums.size() - 1]) {
            return nums.size();
        }
        return binarySearch(0, (nums.size() - 1) /2, nums.size() -1, target, nums);
    }
    
    int binarySearch(int low, int med, int high, int target, vector<int>& nums) {
        if (nums[med] == target) {
            return med; 
        }
        if (low == med) {
            return low +1; 
        }
        if (nums[med] > target) {
            return binarySearch(low, (low+med)/2, med, target, nums);
        }
        if (nums[med] < target) {
            return binarySearch(med, (med+high)/2, high, target, nums);
        }
        return -1; 
    }
};
