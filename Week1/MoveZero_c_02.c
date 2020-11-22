void moveZeroes(int* nums, int numsSize){
    int i,j = 0;
    for(; i < numsSize; i++){
        if(nums[i] != 0){
            nums[j++] = nums[i];
        }
    }
    for(; j < numsSize; j++){
        nums[j] = 0;
    }  
}
//引入两个下标变量，一次循环移位，一次循环补零
