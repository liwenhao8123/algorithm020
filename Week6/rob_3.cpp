//方法三：  时间复杂度O(n)  空间复杂度O(1)
//由于计算第三个房间的结果只跟它的前两个房间有关系，所以可利用两个变量动态存储中间结果
//不用再开辟一维数组DP[0..n], DP方程结构不变，调整下变量名：
//tmp = max(second, nums[i] + first)
//循环中递推更新second和first值
//first  = second;
//second = tmp;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n = nums.size();
        if (n == 1)
            return nums[0];
        
        int first  = nums[0];
        int second = max(first, nums[1]);

        for (int i = 2; i < n; i++){
            int tmp = max(second, nums[i] + first);
            first = second;
            second = tmp;
        }
        return second;
    }
};