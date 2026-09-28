class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int noDelete = arr[0];
        int oneDelete = INT_MIN;

        int ans = arr[0];

        for(int i = 1; i< arr.size(); i++)
        {
            int v1 = arr[i];
            int v2 = noDelete + arr[i];

            int newNoDelete = max(v1,v2);

            int v3;

            if(oneDelete == INT_MIN)
               v3 = INT_MIN; 
            else
               v3 = oneDelete + arr[i];
               
            int v4 = noDelete;

            int newOneDelete = max(v3,v4);

            noDelete = newNoDelete;
            oneDelete = newOneDelete;

            ans = max(ans,max(noDelete, oneDelete));
        }
        return ans;
        
    }
};