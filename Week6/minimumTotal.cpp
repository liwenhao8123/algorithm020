/*
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
*/

/*
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        //bottom - up 自底向上，从倒数第二行开始
        for (int i = triangle.size() - 2; i >= 0; i--){
            for (int j = 0; j <= i; j++){
                dp[i][j] += min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};
*/
//创建DP并复制一份数据到DP
//递推方程：
//dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
//由于DP原始数据与传入的triangle是一样的，可优化递推方程为：
//dp[i][j] += min(dp[i+1][j], dp[i+1][j+1]);
//从底向上递推，最后结果dp[0][0]
//时间复杂度O(n^2) 空间复杂度O(n^2))


//优化空间复杂度，由于两行数据之间是推导出来的，可使用一维数组来递推，优化空间复杂度为O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.back()); 
        //bottom - up 自底向上，从倒数第二行开始
        for (int i = triangle.size() - 2; i >= 0; i--){
            for (int j = 0; j <= i; j++){
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};
//如果允许在传入的数组上直接操作，就不用了新开辟空间了，空间复杂度为O(1)，但这样不太合习惯