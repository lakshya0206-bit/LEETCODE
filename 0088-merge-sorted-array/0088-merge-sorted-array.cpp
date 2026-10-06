class Solution {
public:
void mergeHelper(vector<int>& nums1, int i,
                     vector<int>& nums2, int j,
                     int k) {

        // Base case: all elements of nums2 are merged
        if (j < 0)
            return;

        // If nums1 is exhausted
        if (i < 0) {
            nums1[k] = nums2[j];
            mergeHelper(nums1, i, nums2, j - 1, k - 1);
            return;
        }

        // Compare elements and place larger one
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            mergeHelper(nums1, i - 1, nums2, j, k - 1);
        }
        else {
            nums1[k] = nums2[j];
            mergeHelper(nums1, i, nums2, j - 1, k - 1);
        }
    }

    void merge(vector<int>& nums1, int m,
               vector<int>& nums2, int n) {

        mergeHelper(nums1, m - 1, nums2, n - 1, m + n - 1);
    }
};
