class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int, int> m;
        m[0] = 1;

        int prefixSum = 0;
        int total = 0;

        for (int i = 0; i < nums.size(); i++) {

            prefixSum += nums[i];

            int rem = ((prefixSum % k) + k) % k;

            if (m.count(rem)) {
                total += m[rem];
            }

            m[rem]++;
        }

        return total;
    }
};