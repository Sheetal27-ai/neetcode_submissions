class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = m - 1;

        int row = -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(matrix[mid][0] <= target){
                row = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        if(row == -1){
            return false;
        }
        int l = 0;
        int h = n - 1;
        while(l <= h){
            int mid = l + (h - l)/2;
            if(matrix[row][mid] == target) {
                return true;
            }
            else if(target > matrix[row][mid]){
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }

        return false;
    }
};
