class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();            // number of rows
    int n = matrix[0].size();         // number of columns
    
    int start = 0;
    int end = m * n - 1;              // last index of imaginary 1D array
    
    while(start <= end) {
        
        int mid = start + (end - start) / 2;
        
        // Convert 1D index to 2D index
        int row = mid / n;
        int col = mid % n;
        
        if(matrix[row][col] == target) {
            return true;              // target found
        }
        else if(matrix[row][col] < target) {
            start = mid + 1;          // search right half
        }
        else {
            end = mid - 1;            // search left half
        }
    }
    
    return false;                     // target not found
}
        
};