
//动态规划  使用二维数组，添加障碍的处理，比较直观，相对好理解些
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid.at(0).size();
        vector<vector<int>> dp(m, vector<int>(n));
        
        if (obstacleGrid[0][0] != 0)
            return 0;
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++){
            dp[i][0] = 1;
        }
        for (int j = 1; j < n && obstacleGrid[0][j] == 0; j++){
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                //DP方程
                if (obstacleGrid[i][j] == 0){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};


//动态规划  使用一维数组，这里调试的半天，各种边界条件的处理很多坑，
//看了题解：有个规律，在遍历的时候只使用了每个位置左边的值和上边的值，其他的都用不到，所以考虑把二维数组转化为一位数组
//巧妙的点在于一维数组的长度是n+1,dp[0]始终是等于0的，相当于增加一个左边界障碍并且值为0，每行处理把 j 从1开始则，每行的第一位元素dp[1] = 上次dp[1] + dp[0]

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid.at(0).size();
        vector<int> dp(n+1);

        if (obstacleGrid[0][0] != 0)
            return 0;
        dp[1] = 1;
        for (int i = 0; i < m; i++){
            for (int j = 1; j <= n; j++){
                //DP方程
                if (obstacleGrid[i][j-1] == 0){
                    dp[j] = dp[j] + dp[j-1];
                }else{
                    dp[j] = 0;
                }
            }
        }
        return dp[n];
    }
};

