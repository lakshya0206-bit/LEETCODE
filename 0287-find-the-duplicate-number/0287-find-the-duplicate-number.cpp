class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        while(true) // since pta h ki cycle exists kr rhi h  isliye fast!=null nhi likha
        {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if(slow == fast)
            break;
        }
        // now finding duplicate number as now slow & fast jis point per milege wahi duplicate hoga
        slow = nums[0];

        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};