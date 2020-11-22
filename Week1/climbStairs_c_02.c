int climbStairs(int n){
    if (n <= 0) return 1;
    if (n <= 2) return n;
    int * array = (int *)calloc(n, sizeof(int));
    array[0] = 1;
    array[1] = 2;
    for (int i = 2; i < n; i++){
        array[i] = array[i - 1] + array[i - 2];
    }
    int temp = array[n-1];
    free(array);
    return temp;
}
//引入数组空间，逐次计算数值并存储，注意释放申请的堆区内存