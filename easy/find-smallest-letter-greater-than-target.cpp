class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0; 
        int high = letters.size() - 1;
        int mid; 
        
        // wrap-around case
        if (target >= letters[letters.size() - 1]) return letters[0];
        
        // bin-search 
        while (low < high) {
            mid = (low + high) / 2; 
            if (letters[mid] > target) {
                high = mid; 
            }
            else if (letters[mid] <= target) {
                low = mid + 1;
            }
        }
        return letters[high]; 
    }
};
