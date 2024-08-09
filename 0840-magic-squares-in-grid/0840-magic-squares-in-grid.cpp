class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int r, int c) {
        // Numbers must be between 1-9 and distinct.
        bool seen[10] = {false};
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                int num = grid[r+i][c+j];
                if(num < 1 || num > 9) return false;
                if(seen[num]) return false;
                seen[num] = true;
            }
        }
        // Check if diagonal sums are same.
        int diagonal1 = grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2];
        int diagonal2 = grid[r][c+2]+grid[r+1][c+1]+grid[r+2][c];
        if(diagonal1 != diagonal2) return false;
        // check if all the row sums are the same as diagonal sums.
        int row1 = grid[r][c]+grid[r][c+1]+grid[r][c+2];
        int row2 = grid[r+1][c]+grid[r+1][c+1]+grid[r+1][c+2];
        int row3 = grid[r+2][c]+grid[r+2][c+1]+grid[r+2][c+2];
        if(row1 != diagonal1 || row2 != diagonal1 || row3 != diagonal1) return false;
        // check if all the column sums are the same as diagonal sums.
        int col1 = grid[r][c] + grid[r+1][c] + grid[r+2][c];
        int col2 = grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1];
        int col3 = grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2];
        if(col1 != diagonal1 || col2 != diagonal2 || col3 != diagonal1) return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i=0;i<=rows-3;i++) {
            for(int j=0;j<=cols-3;j++) {
                if(isMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};