class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char,int> need;
        for(int i = 0; i<s.size(); i++)
        {
            need[s[i]]++;
        }

        bool odd = false;

        int ans = 0;

        for(auto i : need)
        {
            int val = i.second;
            if(val % 2 == 0)
            {
                ans = ans + val;
            }
            else {
                odd = true;
                ans = ans + val -1;
            }
        }
        if(odd == false)
        {
            return ans;
        }
       
            return ans+1;
    
    }
};