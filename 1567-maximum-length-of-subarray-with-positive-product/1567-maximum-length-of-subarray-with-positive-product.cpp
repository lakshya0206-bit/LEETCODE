class Solution {
public:
    int getMaxLen(vector<int>& nums) {

        int positive = 0;
        int negative = 0;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            int v1 = positive;
            int v2 = negative;

            if(nums[i] > 0)
            {
                positive = v1 + 1;

                if(v2 > 0)
                {
                    negative = v2 + 1;
                }
                else
                {
                    negative = 0;
                }
            }
            else if(nums[i] < 0)
            {
                if(v2 > 0)
                {
                    positive = v2 + 1;
                }
                else
                {
                    positive = 0;
                }

                negative = v1 + 1;
            }
            else
            {
                positive = 0;
                negative = 0;
            }

            ans = max(ans, positive);
        }

        return ans;
    }
};
        
