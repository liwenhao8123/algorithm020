/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
*/

//采用双指针法，前后两个指针进行操作
void moveZeros(int * nums, int numsSize){
    int front = 0;
    for (int cur = 0; cur < numsSize; cur++){
        if (nums[cur] != 0){
            int tmp = nums[cur];
            nums[cur] = nums[front];
            nums[front++] = tmp;
        }
    }
}