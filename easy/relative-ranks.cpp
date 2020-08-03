using namespace std;
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> sorted (nums.size()); 
        copy(nums.begin(), nums.end(), sorted.begin()); 
        sort (sorted.begin(), sorted.end(), greater<int>());
        
        vector<string> return_vector(nums.size()); 
        
        map<int,int> pos_map; 
        for (int i = 0; i < nums.size(); i ++) {
            pos_map.insert({nums[i], i});
        }
        
        if (nums.size() == 0) {
            return return_vector; 
        }
        return_vector[pos_map[sorted[0]]] = "Gold Medal";
         if (nums.size() == 1) {
             return return_vector; 
         }
        return_vector[pos_map[sorted[1]]] = "Silver Medal"; 
        if (nums.size() == 2) {
            return return_vector; 
        }
        return_vector[pos_map[sorted[2]]] = "Bronze Medal"; 
        
        
        int place = 4; 
        for (int i = 3; i < nums.size(); i ++) {
            return_vector[pos_map[sorted[i]]] = to_string(place); 
            place++; 
        }
        return return_vector; 
    }
};
