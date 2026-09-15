class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int low = 0;
        int high = 0;

        int ans = 0;

        unordered_map<int,int>mp;

        while(high<n)
        {
            mp[fruits[high]]++;

            while(mp.size()>2)
            {
                mp[fruits[low]]--;

                if(mp[fruits[low]]==0)
                {
                    mp.erase(fruits[low]);
                }

                low++;
            }
            ans = max(ans, high-low+1);

            high++;
        }
        return ans;
    }
};