/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//定义全局变量方便访问
int * tmp;  //用于存放找子集过程的中间项
int tSize;  //用于记录找子集过程中tmp已保存的元素数
int tCol;   //用于记录找到第几个子集
int ** result = NULL;
int * resultCol = NULL;

//cur用于记录找子集过程中当前使用到1...n 的哪个元素

void dfs(int cur, int n, int k)
{
    //剪枝，如果当前已找到的元素数 + 从[cur,n]的元素数 比k小，则即使[cur,n]全都用了也不够k个元素，可以返回了
    if (tSize + (n - cur + 1) < k){
        return;
    }
    //停止条件，说明如果当前已找到的元素数等于k，则返回
    if (tSize == k){
        //保存记录结果
        int * dfs_tmp = (int *)malloc(sizeof(int) * k);
        memcpy(dfs_tmp, tmp, sizeof(int) * k);
        result[tCol] = dfs_tmp;
        resultCol[tCol++] = k;
        return;  
    }
    //停止条件，如果cur == n + 1则说明元素都用完了，但如果上面两个满足一个都不会出现该条件

    //本层逻辑： 当前元素用或者不用
    tmp[tSize++] = cur;
    dfs(cur + 1, n, k);
    tSize--;    //如果不用tSzize--，不赋值，把空间流出来
    dfs(cur + 1, n, k);
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int retSize = 1 << n; //计算2^n利用位移运算即可

    result = (int **)malloc(sizeof(int *) * retSize);
    resultCol = (int *)malloc(sizeof(int) * retSize);
    tmp = (int *)malloc(sizeof(int) * n);
    
    tSize = tCol = 0;
    dfs(1, n, k);

    *returnColumnSizes = resultCol;
    *returnSize = tCol;
    return result;
}