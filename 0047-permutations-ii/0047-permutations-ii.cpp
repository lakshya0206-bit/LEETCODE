class Solution {
public:

    void solve(vector<int>& nums,
               vector<vector<int>>& ans,
               vector<int>& temp,
               vector<bool>& visited)
    {
        // Base Case
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            // Already used
            if(visited[i])
                continue;

            // Skip duplicate
            if(i>0 &&
               nums[i]==nums[i-1] &&
               visited[i-1]==false)
                continue;

            // Choose
            visited[i]=true;
            temp.push_back(nums[i]);

            // Recursive call
            solve(nums,ans,temp,visited);

            // Backtrack
            temp.pop_back();
            visited[i]=false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(nums.size(),false);

        solve(nums,ans,temp,visited);

        return ans;
    }
};