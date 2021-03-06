# lwh practice algorithm

### 关于排序结合扩展资料的结合进行下总结：

## 冒泡排序：
（时间复杂度O(n²) 原地排序 稳定排序）：两层循环，内层循环执行一轮通过交换得到未排序的最大值并“冒泡”到最后

## 插入排序：
（时间复杂度O(n²) 原地排序 稳定排序）：从前往后分为已排序区和未排序区，遍历未排序区元素，插入排序区对应位置，原来已排序的元素需要向后进行搬移

## 归并排序
（时间复杂度O(nlogn) 非原地排序 空间复杂度O(n) 稳定排序）利用分治思想（分而治之，将大问题分解为小的子问题），通常递归实现，把数组从中间分成前后两部分，然后对前后两部分分别排序，再将排好的两部分合并在一起（合并的时候需要新开辟空间来存储合并的结果）

## 快速排序
（时间复杂度O(nlogn) 原地排序 稳定排序）利用分治思想，通常递归实现。从要排序的数组中下标从 p 到 r 之前的数组，选择 p 到 r 之前的任意数据作为pivot（分区点），进行遍历将将小于pivot的放到左边，大于pivot的放到右边，中间是pivot，然后再分别对 p 到 q-1 和 q+1 到 r 进行排序（pivot点的选择是关键）

如果原始数据本就是有序的或接近有序，那么快排代码实现时，如果用最后一个元素作为pivot，那么时间复杂度会退化到O(n²)，如何优化，关键在pivot点的选择，理想的分区点是：被分区点分开的两个分区中，数据的数量差不多。常用的两种方法：1.三数取中（或多数取中），从首、中、尾分别取数并进行比较，选择中间值作为pivot  2.随机法：随机选择一个元素作为pivot

## 特殊排序（桶排序、计数排序、基数排序）
（时间复杂度O(n) 非原地排序 稳定排序）这三种排序方法是 非基于比较 的，使用在特殊的场景下。

桶排序：核心思想是将要排序的数据分到几个有序的桶里，每个桶里的数据再单独进行排序。桶内排序完成之后，再把每个桶里的数据按照顺序依次取出，组成的序列就是有序的了。
计数排序：是桶排序的一种特殊情况，就是桶的分割粒度是一个数。
基数排序：需要可以分割出独立的“位”来比较，而且位之间有递进的关系，如果A数据的高位比B数据大，那剩下的地位就不用比较了，并且每一位的数据范围不能太大，要能用线性排序算法来排序。

## 如何实现一个通用的、高性能的排序函数？

## 分析C语言中glibc库中qsort函数的实现：
1.qsort优先使用归并排序，当小数量的排序时，比如1K 2K等，另外申请空间问题不太（空间换时间的方式）
2.如果数据量比较大是，qsort使用快排算法，pivot点的选择采用三数取中法
3.当快速排序不断分解时，如果要排序的元素小于等于4时，qsort采用了插入排序 （因为在小规模数据面前，O(n²)并不一定比O(nlogn)执行时间长）
4.快排的实现要警惕堆栈溢出，如果递归的深度非常高，可能会导入编译分配的栈空间不足而引起溢出。一种方法是：限制递归深度  二方法：在进程空间的内存堆区，模拟实现一个函数调用栈，手动模拟系统或虚拟机本身提供的入栈、出栈的过程。

