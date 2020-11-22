void moveZeroes(int* nums, int numsSize){
    int i,j = 0;
    for(; i < numsSize; i++){
        if(nums[i] != 0){
            //do swap
            int temp = nums[i];
            nums[i] = nums[j];
            //nums[j] = temp;
            //j++;
            nums[j++] = temp; //这个复合语句执行效率提高4ms,内存利用减少0.4MB
        }
    } 
}