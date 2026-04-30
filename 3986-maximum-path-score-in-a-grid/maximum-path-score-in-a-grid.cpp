class Solution {
    // Use a vector to store the memo table on the heap
    vector<vector<vector<int>>> memo;

    int solve(vector<vector<int>>& grid, int i, int j, int k) {
        // 1. Boundary Check
        if (i >= grid.size() || j >= grid[0].size()) return -1e9;

        // 2. Calculate Cost & Remaining Budget
        int cost = (grid[i][j] > 0) ? 1 : 0;
        if (k - cost < 0) return -1e9;

        // 3. Base Case: Reached the bottom-right cell
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return grid[i][j];
        }

        // 4. Memoization Lookup
        if (memo[i][j][k] != -1) return memo[i][j][k];

        // 5. Recursive Step
        int right = solve(grid, i, j + 1, k - cost);
        int down = solve(grid, i + 1, j, k - cost);

        int best_next = max(right, down);

        // 6. Handle unreachable paths
        if (best_next <= -1e8) {
            return memo[i][j][k] = -1e9;
        }

        return memo[i][j][k] = grid[i][j] + best_next;
    }

public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Initialize memo table on the heap: [m][n][k+1]
        // k can be up to 100 in most LeetCode grid problems, adjust if needed
        memo.assign(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        
        int result = solve(grid, 0, 0, k);
        
        return (result < 0) ? -1 : result;
    }
};