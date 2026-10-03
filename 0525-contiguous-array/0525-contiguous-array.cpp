class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int zero = 0;
        int one = 0;
        int ans = 0;

        unordered_map<int, int>f;

        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            zero++;
            else
            one++;

            int diff = zero - one;

            //case 1

            if(diff == 0)
            {
                ans = max(ans,i+1);
                continue;
            }
            if(f.find(diff)==f.end())
            {
                f[diff]=i;
            }
            else{
                int idx = f[diff];
                int len = i - idx;

                ans = max(len, ans);
            }
            
        }
        return ans;
        
    }
};