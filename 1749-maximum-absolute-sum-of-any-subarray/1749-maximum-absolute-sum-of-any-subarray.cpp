class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int maxend = nums[0];
        int minend = nums[0];

        int maxsum = nums[0];
        int minsum = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            int v1 = nums[i];
            int v2 = maxend + nums[i];

            maxend = max(v1,v2);

            int v3 = nums[i];
            int v4 = minend + nums[i];

            minend = min(v3,v4);

            maxsum = max(maxsum, maxend);
            minsum = min(minsum, minend);


        }
        return max(abs(maxsum),abs(minsum));
    }
};