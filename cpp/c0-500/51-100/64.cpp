#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = grid[0][0];  // Start position

    // Fill the first row
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    // Fill the first column
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    // Fill the rest of the DP table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[m-1][n-1];  // Bottom-right corner
}

int main() {
    vector<vector<int>> grid1 = {{1,3,1}, {1,5,1}, {4,2,1}};
    cout << minPathSum(grid1) << endl; // Output: 7

    vector<vector<int>> grid2 = {{1,2,3}, {4,5,6}};
    cout << minPathSum(grid2) << endl; // Output: 12

    return 0;
}
