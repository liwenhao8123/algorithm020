/*
1.对于最上边的一行的每一个元素，最小路径总和为之前所有元素的值相加（只用把左边值累加起来，不用考虑上方）
即当i = 0时， dp[0][j] = nums[0][j] + dp[0][j-1];
2.对于最左边的一列的每一个元素，最小路径总和为上方所有元素的值相加（只用把上面值累加起来，不用考虑左边）
即当j = 0时， dp[i][0] = nums[i][0] + dp[i-1][0];
3.对于其他的点，最小路径和为min(上方点路径和，左边点路径和)
dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + nums[i][j]
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        if (row == 0 || col == 0)
            return 0;

        vector<vector<int>> dp(row, vector<int>(col));

        dp[0][0] = grid[0][0];
        for (int j = 1; j < col; j++){
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        for (int i = 1; i < row; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for (int i = 1; i < row; i++){
            for (int j = 1; j < col; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[row-1][col-1];
    }
};