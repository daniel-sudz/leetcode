using namespace std; 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l_ref = 0; 
        int r_ref = height.size() -1; 
        int max_height = 0; 
        while (l_ref <= r_ref) {
            int tower_min = min(height[l_ref], height[r_ref]); 
            max_height = max(max_height, tower_min * (r_ref - l_ref)); 
            if (height[l_ref] == tower_min)
                l_ref ++; 
            if (height[r_ref] == tower_min)
                r_ref --;
        }
        return max_height; 
    }
};
