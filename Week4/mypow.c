double fastPow(double x, long long n){
    if (n == 0)
        return 1.0;
    double half = fastPow(x, n>>1);
    return (n & 1) == 0 ? half * half : half * half * x;
}

double myPow(double x, int n){
    long long N = n;
    return N >= 0 ? fastPow(x, N) : 1.0/fastPow(x, -N);
}