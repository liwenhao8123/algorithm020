int climbStairs(int n){
    if (n <= 3)
        return n;
    int fn1 = 2, fn2 = 3, fn3;
    for (int i = 3; i < n; i++){
        fn3 = fn1 + fn2;
        fn1 = fn2;
        fn2 = fn3;
    }
    return fn3;
}