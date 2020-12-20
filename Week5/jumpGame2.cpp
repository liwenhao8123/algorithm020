/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:

假设你总是可以到达数组的最后一个位置
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0;  //记录可到达的最远位置
        int target = 0;  //存储边界条件
        int step = 0;    //记录跳跃次数，每次到边界条件就+1
        for (int i = 0; i < nums.size() - 1; i++){ //注意需要nums.size() - 1 因为最后一个元素作为边界条件不跳跃次数
            maxPos = max(nums[i] + i, maxPos);
            if (i == target){
                target = maxPos;
                step++;
            }
        }
        return step;
    }
};