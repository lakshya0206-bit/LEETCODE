class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {

        vector<vector<int>> ans;

        int n = a.size();
        int i = 0;

        int start2 = b[0];
        int end2 = b[1];

        while (i < n)
        {
            int start1 = a[i][0];
            int end1 = a[i][1];

            if (end1 < start2)
            {
                ans.push_back({start1, end1});
            }
            else if (start1 > end2)
            {
                ans.push_back({start2, end2});

                while (i < n)
                {
                    ans.push_back(a[i]);
                    i++;
                }

                return ans;
            }
            else
            {
                start2 = min(start1, start2);
                end2 = max(end1, end2);
            }

            i++;
        }

        ans.push_back({start2, end2});

        return ans;
    }
};