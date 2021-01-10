
// 利用位运算，n & 1 结果判断最低位是否为1,然后 n 右移一位
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0){
        if (n & 1){
            count++;
        }
        n >>= 1;
    }
    return count;
}

// 将 n 和 n - 1 做与运算，会把最后一个 1 的位变成 0，依次执行并记录个数
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0){
        count++;
        n &= (n-1);
    }
    return count;
}