class Solution {
public:
    bool solve(string &s, string &t, int i, int j)
    {
        // All characters of s matched
        if(i == s.size())
            return true;

        // t finished but s still left
        if(j == t.size())
            return false;

        // Characters match
        if(s[i] == t[j])
            return solve(s, t, i + 1, j + 1);

        // Characters do not match
        return solve(s, t, i, j + 1);
    }

    bool isSubsequence(string s, string t)
    {
        return solve(s, t, 0, 0);
    }
};