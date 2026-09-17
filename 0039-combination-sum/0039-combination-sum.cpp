class Solution {
public:

    void combi(vector<int>& candidates, int target, int index,vector<vector<int>> & ans , vector<int>&temp)
    {
        if(index == candidates.size())
        {
            if(target == 0)  // target 0 becoz hme jb target achive ho jayega and hum sare elements ko checkout kr lrgr tb wo ans m temp ki value dalege
            {

            ans.push_back(temp);
            }

            return;
        }

        if( candidates[index] <= target)
        {
            temp.push_back(candidates[index]);

            combi( candidates,target - candidates[index], index, ans, temp); // like target = 7 and canndidates[index] = 2 so 7-2 =5 not make it reduce until target == 0

            temp.pop_back(); // pop back isliye krte h taki no wali condition per bhi jaa sake , see tree diagram
        }

        // not taken

         combi( candidates,target, index + 1, ans, temp);


    }



    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

         vector<vector<int>> ans;
        vector<int> temp;

        combi(candidates,
              target,
              0,
              ans, temp);

        return ans;
        
    }
};