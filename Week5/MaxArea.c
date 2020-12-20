//给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
//在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。
//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

//暴力法，两层循环，计算当前坐标到后面坐标构成的容器面积，引入max变量保存最大的值

//双指针，左右往中间夹逼，比较当前左右指针指向的值，取其中较小的作为tmp_height参与计算
//夹逼过程中宽度在不断减小，值相对较小的一方继续移动，以期望在后面的元素中找到更height的值而得到更大的面积

int maxArea(int * height, int heightSize){
    int max = 0;
    int left = 0, right = heightSize - 1;
    while (left < right){
        int tmp_height = height[left] < height[right] ? height[left++] : height[right--];
        int tmp_Area = tmp_height * (right - left + 1);
        if (max < tmp_Area){
            max = tmp_Area;
        }
    }
}