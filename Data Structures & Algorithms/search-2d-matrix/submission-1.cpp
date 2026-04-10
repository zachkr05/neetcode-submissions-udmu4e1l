class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        



        // Binary search the rows
        int lastRow = matrix.size()-1;
        int lastCol = matrix[0].size()-1;

        int top = 0;
        int bot = lastRow;

        //While we still have indices to check
        while(top<=bot){
            int m = (top + (bot - top)/2);
            if (target > matrix[m][lastCol]){
                top=m+1;
            }
            else {
                bot=m-1;
            }
        }

        int curr_row = top;
        if (curr_row>= matrix.size()) return false;
        if (target<matrix[curr_row][0]) return false;



        int l =0;
        int r = lastCol;

        while (l<=r){
            int m = (l+(r-l)/2);
            if(target == matrix[curr_row][m]) return true;
            else if(target<matrix[curr_row][m]) r=m-1;
            else l = m+1;
        }
        return false;
    }
};
