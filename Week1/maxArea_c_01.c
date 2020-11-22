#include <stdio.h>

int maxArea(int* height, int heightSize){
    int max = 0;
    int left = 0 , right = 0;
    for (; left < heightSize-1; left++){
        for (right = left+1; right < heightSize; right++){
            //比较起点与终点取min，然后乘以长度flag-start
            int height_tmp = height[left] < height[right] ? height[left] : height[right];
            int temp = height_tmp * (right-left);
            if (temp > max)
                max = temp;
        }
    }
    return max;
}

int main(int argc, char * argv){
    int height[] = {1,8,6,2,5,4,8,3,7};
    printf("max is %d\n", maxArea(height, sizeof(height)/sizeof(int)));
    return 0;
}