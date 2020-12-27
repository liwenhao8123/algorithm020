/*
空间复杂度优化为使用一维数组O(column)
dp[0] = grid[0][0];
1.定义一维数组，先计算并存储最上边的一行的每个最小路径和
方法：之前所有元素的值相加（只用把左边值累加起来，不用考虑上方）
即当i = 0时， dp[j] = grid[0][j] + dp[j-1];
2.当i > 0时，依次用dp数组计算第i行每个元素的最小路径和
要先计算dp[0] = dp[0] + grid[i][0];
然后循环计算1...j的元素
dp[j] = min(dp[j], dp[j-1]) + grid[i][j]
上一行计算的dp[j]  和 前一次计算的dp[j-1] 比较取较小的值
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        if (row == 0 || col == 0)
            return 0;

        vector<int> dp(col);

        dp[0] = grid[0][0];
        for (int j = 1; j < col; j++){
            dp[j] = dp[j-1] + grid[0][j];
        }
        for (int i = 1; i < row; i++){
            dp[0] += grid[i][0];
            for (int j = 1; j < col; j++){
                dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
            }
        }
        return dp[col-1];
    }
};