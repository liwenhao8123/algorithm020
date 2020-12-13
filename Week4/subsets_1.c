/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//按照位运算的方式迭代，以[5,2,1]为例
//000   []    
//001   [1]
//010   [2]
//011   [2,1]
//100   [5]
//101   [5,1]
//110   [5,2]
//111   [5,2,1]
//第几位置位则就取该位相应的元素来用

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int ** result = NULL;
    int * resultCol = NULL;
    int retSize = 1 << numsSize; //计算2^n利用位移运算即可
    int tmp[numsSize];

    result = (int **)malloc(sizeof(int *) * retSize);
    resultCol = (int *)malloc(sizeof(int) * retSize);

    for (int mask = 0; mask < retSize; mask++){
        int colSize = 0;
        //遍历所有的可能
        for (int i = 0; i < numsSize; i++){
            //位运算进行比较
            if (mask & (1 << i)) {
                tmp[colSize++] = nums[i];
            }
        }
        int * buf = (int *)malloc(sizeof(int) * colSize);
        memcpy(buf, tmp, sizeof(int) * colSize);
        resultCol[mask] = colSize;
        result[mask] = buf;
    }
    *returnSize = retSize;
    *returnColumnSizes = resultCol;
    return result;
}