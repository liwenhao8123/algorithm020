
//动态递推  使用二维数组
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                //DP方程
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

//动态递推  使用一维数组，优化了空间复杂度
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n);
        for (int j = 0; j < n; j++)
            dp[j] = 1;
        for (int i = 0; i < m - 1; i++){
            for (int j = 1; j < n; j++){
                //DP方程
                dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp[n-1];
    }
};