#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        
        // 1. Sort the input array
        std::sort(nums.begin(), nums.end());
        
        // 2. Iterate through the array fixing the first element
        for (int i = 0; i < n - 2; ++i) {
            // Optimization: If the fixed element is positive, the remaining 
            // numbers are also positive, so they can never sum up to 0.
            if (nums[i] > 0) break;
            
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // 3. Initialize two pointers for the remaining two elements
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];
                
                if (current_sum == 0) {
                    // Found a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Advance pointers and skip duplicates to prevent duplicate triplets
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    // Move inward after handling duplicates
                    left++;
                    right--;
                } 
                else if (current_sum < 0) {
                    // Sum is too small, move left pointer right to increase the sum
                    left++;
                } 
                else {
                    // Sum is too large, move right pointer left to decrease the sum
                    right--;
                }
            }
        }
        
        return result;
    }
};
