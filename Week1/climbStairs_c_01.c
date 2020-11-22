int climbStairs(int n){
    if (n <= 2)
        return n;
    int fn1 = 1, fn2 = 2, fn3 = 0;
    for (int i = 3; i <= n; i++){
        fn3 = fn1 + fn2;
        fn1 = fn2;
        fn2 = fn3;
    }
    return fn3;
}
//采用循环递推方式，只关注最近三个变量