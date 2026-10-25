class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, vector<pair<int, int>>& dir){
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col] == 1) return;
        grid[row][col] = 1;
        for(auto d : dir){
            dfs(grid, row+d.first, col+d.second, dir);
        }
    } 
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

        for(int i=0; i<rows; i++){
            if(grid[i][0] == 0) dfs(grid, i, 0, dir);
            if(grid[i][cols-1] == 0) dfs(grid, i, cols-1, dir);
        }
        for(int i=0; i<cols; i++){
            if(grid[0][i] == 0) dfs(grid, 0, i, dir);
            if(grid[rows-1][i] == 0) dfs(grid, rows-1, i, dir);
        }

        int islands = 0;

        for(int row=0; row<rows; row++){
            for(int col=0; col<cols; col++){
                if(grid[row][col] == 0){
                    islands++;
                    dfs(grid, row, col, dir);
                }
            }
        }

        return islands;

    }
};