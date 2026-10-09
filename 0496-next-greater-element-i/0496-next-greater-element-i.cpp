class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;
        vector<int> nge(nums2.size(), -1);

        // Find Next Greater Element for nums2
        for (int i = 0; i < nums2.size(); i++) {

            while (!st.empty() && nums2[st.top()] < nums2[i]) {
                nge[st.top()] = nums2[i];
                st.pop();
            }

            st.push(i);
        }

        // Build answer for nums1
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {

            for (int j = 0; j < nums2.size(); j++) {

                if (nums1[i] == nums2[j]) {
                    ans.push_back(nge[j]);
                    break;
                }
            }
        }

        return ans;
    }
};