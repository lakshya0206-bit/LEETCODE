class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {

        vector<vector<int>> ans;

        int start1 = b[0];
        int end1 = b[1];

        bool insert = false;

        for(int i = 0; i < a.size(); i++)
        {
            int start2 = a[i][0];
            int end2 = a[i][1];

            if(end2 < start1)
            {
                ans.push_back({start2,end2});
            }
            else if(start2 > end1)
            {
                if(insert == false)
                {
                    ans.push_back({start1, end1});
                    insert = true;
                }

                ans.push_back({start2,end2});
            }
            else{
                start1 = min(start1, start2);
                end1 = max(end1, end2);
            }
        }

        if(insert == false)
        {
            ans.push_back({start1, end1});
        }

        return ans;
    }
};

   