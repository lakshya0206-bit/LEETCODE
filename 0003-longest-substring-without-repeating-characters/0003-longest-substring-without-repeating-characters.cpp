class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        int low = 0;
        int high = 0;

        int ans = 0;

        unordered_map<int,int>mp;

        while(high<n)
        {
            mp[s[high]]++;

            while(mp[s[high]]>1)
            {
                mp[s[low]]--;

                if(mp[s[low]]==0)
                {
                    mp.erase(s[low]);
                }

                low++;
            }
            ans = max(ans, high-low+1);

            high++;
        }
        return ans;
    }
};
        
    