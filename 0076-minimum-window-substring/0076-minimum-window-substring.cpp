class Solution {
public:
    string minWindow(string s, string t) {

        int total = t.size();

        unordered_map<char,int>m;
        for(int i=0 ; i < t.size(); i++)

        m[t[i]]++;

        int start = 0, end = 0, ans = INT_MAX, index = -1;

while (end < s.size())
{
    // [Annotation in red pointing to 'end': "or end ko initially start per rkhna h as we are increasing window"]
    
    m[s[end]]--; // decrease count of char
    
    if (m[s[end]] >= 0) // if count is not -ve
        total--;        // decrease the total.

    // can we decrease the size of window.
    
    // [Annotation in red margin: "Condn to decrease window size"]
    while (total == 0 && start <= end)
    {
        // update the length of substring
        if (ans > end - start + 1)
        {
            // [Annotation in red: "update ans"]
            ans = end - start + 1;
            index = start;
        }
        
        // [Annotation in red margin: "start aage badha do to decrease window size"]
        m[s[start]]++;
        
        if (m[s[start]] > 0) // If count is +ve
            total++;         // increase the total
            
        start++; // move the start, decrease the size
    }
    
    // Increase the size
    end++; // [Annotation in red: "-> increase wala part in"]
}

if (index == -1)
    return "";

string str = "";
for (int i = index; i < index + ans; i++)
{
    str += s[i];
}
return str;
        
    }
};