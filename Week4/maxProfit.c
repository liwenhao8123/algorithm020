//贪心算法
//只要当天比前一天值高，则就在前一天买入，当天出售，累加每次的涨幅，就得到了结果

int maxProfit(int* prices, int pricesSize){
    int result = 0;
    for (int i = 1; i < pricesSize; i++){
        int tmp = prices[i] - prices[i - 1];
        if (tmp > 0)
            result += tmp;
    }
    return result;
}