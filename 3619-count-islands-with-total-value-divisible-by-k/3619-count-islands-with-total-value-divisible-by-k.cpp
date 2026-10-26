class Solution {
public:
    vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

    long long dfs(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0) return 0;
        long long sum = grid[r][c];
        grid[r][c] = 0;

        for(auto d : dir){
            sum += dfs(grid, r+d.first, c+d.second);
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int r = grid.size(), c = grid[0].size(), ans = 0;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] != 0){
                    long long sum = dfs(grid, i, j);
                    if(sum%k == 0) ans++;
                }
            }
        }

        return ans;
    }
};