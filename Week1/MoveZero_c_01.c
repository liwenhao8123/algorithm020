void moveZeroes(int* nums, int numsSize){
    int j = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] != 0){
            nums[j] = nums[i];
            if(i != j)
                nums[i] = 0;
            j++;
        }
    }
}

//一次循环，引入两个下标变量（双指针），需要注意元素全为整数，增加i != j的判断
