/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int CompareByIncrease(const void* a, const void* b)
{
    return *(int*)a - *(int*)b; // 快排构造递增序列
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if ( numsSize < 3 ){
        return NULL;
    }
    int cur = 0;
    //调试了半天还是弄不明白这里为什么要开辟 (numsSize)*(numsSize) 这么大的空间
    int** returnArray = (int**)malloc(sizeof(int *) * (numsSize)*(numsSize));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (numsSize)*(numsSize)); 
    qsort(nums, numsSize, sizeof(int), CompareByIncrease);

    for (; cur < numsSize - 2;){
        if (nums[cur] > 0)
            break;
        int left = cur + 1;
        int right = numsSize - 1;
        while (left < right){
            if (nums[left] + nums[right] + nums[cur] < 0)
                left++;
            else if (nums[left] + nums[right] + nums[cur] > 0)
                right--;
            else {
                returnArray[*returnSize] = (int*)malloc(sizeof(int) * 3); // 每次找到一组，二级指针就分配三个空间
                (*returnColumnSizes)[*returnSize] = 3; 
                returnArray[*returnSize][0] = nums[cur];
                returnArray[*returnSize][1] = nums[left];
                returnArray[*returnSize][2] = nums[right];
                (*returnSize)++;
                //注意要去掉重复的
                while ( (nums[left] == nums[++left]) && (left < right) ) ;
                while ( (nums[right] == nums[--right]) && (left < right) ) ;
            }    
        }
        while ( (nums[cur] == nums[++cur]) && (cur + 1 < numsSize - 1) ) ;
    }
    return returnArray;
}