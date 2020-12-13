//贪心算法
//rightmax 记录从出发开始每一步可跳跃的最远的位置，每步取max(rightmax, i+nums[i])
//如果存在i > rightmax 不处理，这种情况说明从前面无法跳到i，nums[i]就没有意义了

bool canJump(int* nums, int numsSize){
    int rightmax = 0;
    for (int i = 0; i < numsSize; i++){
        if (i <= rightmax){
            rightmax = rightmax > (i + nums[i]) ? rightmax : (i + nums[i]);
            if (rightmax >= numsSize - 1)
                return true;
        }
    }
    return false;
}