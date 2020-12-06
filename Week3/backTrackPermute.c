/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//回溯法
//1，以选取的字符数 iCurPos 为索引，进行回溯
//2，下一层选取数字的规则，只能选取剩下没有使用过的数字
//3，结束条件，数字填完了

//回溯函数
void backTrackPermute(int* nums, int numsSize, int** pRet, int* pUsed, int* pRetPos, int iCurPos){
    int     i       = 0;
    int     iTmp    = 0;
    //1 结束条件，当所有
    if (iCurPos == numsSize)
    {
        *pRetPos += 1;
        memcpy(pRet[*pRetPos], pRet[(*pRetPos) - 1], sizeof(int) * numsSize);       //进行下一个结果的填写，将当前结果拷贝，否则前面的值为0
        return;
    }

    //2,回溯处理
    for (i = 0; i < numsSize; i++)
    {
        if (0 == pUsed[i])
        {
            iTmp = i;
            pRet[*pRetPos][iCurPos] = nums[i];
            pUsed[i] = 1;
            backTrackPermute(nums, numsSize, pRet, pUsed, pRetPos, iCurPos + 1);

            //3,回退处理
            pUsed[iTmp] = 0;
        }
    }

    return;
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int         i           = 0;
    int         iRetSize    = 1;
    int**       pRet        = NULL;
    int*        pRetCol     = NULL;
    int*        pUsed       = NULL;
    int         iRetPos     = 0;

    //1,全排列可以先计算出结果有多少个数组
    for (int i = 1; i <= numsSize; i++){
        iRetSize *= i;
    }

    //2,动态申请存储空间
    //指针数组，该数组每个成员存放指向一种排列结果
    pRet = (int**)malloc(sizeof(int*) * (iRetSize + 1));
    //申请int型数组，依次存放每行有多少列
    pRetCol = (int*)malloc(sizeof(int) * (iRetSize + 1));
    //递归过程中使用
    pUsed = (int*)malloc(sizeof(int) * numsSize);
    memset(pUsed, 0x00, sizeof(int) * numsSize);

    for (i = 0; i <= iRetSize; i++)
    {
        //申请空间用于存放每一种排列组合
        pRet[i] = (int*)malloc(sizeof(int) * numsSize);
        memset(pRet[i], 0x00, sizeof(int) * numsSize);
        //每一行的成员都是numSize列数
        pRetCol[i] = numsSize;
    }
    //3,调用回溯函数，RetPos用于记录已经使用了几个数字，可以理解过递归的第几层
    backTrackPermute(nums, numsSize, pRet, pUsed, &iRetPos, 0);
    //4,释放空间
    free(pUsed);
    //5,返回
    *returnSize = iRetSize;
    *returnColumnSizes = pRetCol;
    return pRet;
}