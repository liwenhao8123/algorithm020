//递归法
//定义全局变量方便访问
int * tmp;  //用于存放找子集过程的中间项
int tSize;  //用于记录找子集过程中tmp已保存的元素数
int tCol;   //用于记录找到第几个子集
int ** result = NULL;
int * resultCol = NULL;

//cur用于记录找子集过程中当前使用到那个nums的元素

void dfs(int cur, int * nums, int numsSize)
{
    //停止条件，说明找到了nums的最后一个元素
    if (cur == numsSize){
        //开辟空间转储tmp数据
        int * dfs_tmp = (int *)malloc(sizeof(int) * numsSize);
        memcpy(dfs_tmp, tmp, sizeof(int) * tSize);
        result[tCol] = dfs_tmp;
        //赋值记录该子集长度
        resultCol[tCol++] = tSize;
        return;
    }
    //本层逻辑： 当前元素用或者不用
    tmp[tSize] = nums[cur];
    tSize++;
    dfs(cur + 1, nums, numsSize);
    tSize--;    //如果不用tSzize--，不赋值，把空间流出来
    dfs(cur + 1, nums, numsSize);
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int retSize = 1 << numsSize; //计算2^n利用位移运算即可

    result = (int **)malloc(sizeof(int *) * retSize);
    resultCol = (int *)malloc(sizeof(int) * retSize);
    tmp = (int *)malloc(sizeof(int) * numsSize);
    
    tSize = tCol = 0;
    dfs(0, nums, numsSize);

    *returnColumnSizes = resultCol;
    *returnSize = tCol;
    return result;
}