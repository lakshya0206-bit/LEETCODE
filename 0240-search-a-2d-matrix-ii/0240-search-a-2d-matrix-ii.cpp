class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
           
    int m = matrix.size();         // number of rows
    int n = matrix[0].size();      // number of columns
    
    int row = 0;                   // start from first row
    int col = n - 1;               // start from last column (top-right)
    
    while(row < m && col >= 0) {
        
        if(matrix[row][col] == target) {
            return true;           // target found
        }
        else if(matrix[row][col] > target) {
            col--;                 // move left
        }
        else {
            row++;                 // move down
        }
    }
    
    return false;                  // target not found
}
};