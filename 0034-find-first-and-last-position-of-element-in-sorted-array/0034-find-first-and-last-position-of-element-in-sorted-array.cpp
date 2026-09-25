class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     int n = nums.size();
    int start = 0, end = n - 1;
    int first = -1, last = -1;
    
    //  Find First Occurrence
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (nums[mid] == target) {
            first = mid;        // store index
            end = mid - 1;      // move left
        }
        else if (nums[mid] < target) {
            start = mid + 1;    // move right
        }
        else {
            end = mid - 1;      // move left
        }
    }

    //  Reset for finding last occurrence
    start = 0;
    end = n - 1;

    //  Find Last Occurrence
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (nums[mid] == target) {
            last = mid;         // store index
            start = mid + 1;    // move right
        }
        else if (nums[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

vector<int> a(2);
a[0] = first;
a[1] = last;

return a;
 }
};