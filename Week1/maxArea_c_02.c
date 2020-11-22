#include <stdio.h>

int maxArea(int* height, int heightSize){
    int max = 0;
    int left = 0 , right = heightSize - 1;
    //双指针向中间收敛的方式
    while(left < right){
        int height_tmp = height[left] < height[right] ? height[left++] : height[right--];
        int temp = height_tmp * (right - left + 1);
        if (temp > max)
            max = temp;
    }
    return max;
}

int main(int argc, char * argv){
    int height[] = {1,8,6,2,5,4,8,3,7};
    printf("max is %d\n", maxArea(height, sizeof(height)/sizeof(int)));
    return 0;
}