class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char, int>> st;

        for (int i = 0; i < s.size(); i++) {

            if (st.empty()) {
                st.push({s[i], 1});
                continue;
            }

            if (st.top().first != s[i]) {
                st.push({s[i], 1});
                continue;
            }

            // Check whether the top character's count
            // is less than k-1
            if (st.top().second < k - 1) {
                pair<char, int> p = st.top();
                st.pop();

                st.push({p.first, p.second + 1});
                continue;
            }

            // If count reaches k-1, remove the pair
            // and the current character completes k duplicates
            st.pop();
        }

        string res = "";

        while (!st.empty()) {
            pair<char, int> p = st.top();
            st.pop();

            while (p.second--) {
                res.push_back(p.first);
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};