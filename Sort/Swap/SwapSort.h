//
// Created by 23276 on 2021/7/30.
//

#ifndef DATASTRUCTURE_SWAPSORT_H
#define DATASTRUCTURE_SWAPSORT_H


// 交换nums数组中i和j的元素
void swap(int nums[], int i, int j);
// 冒泡排序
void BubbleSort(int nums[], int length);
// 快速排序
void QuickSort(int nums[], int length);
void Quick_Sort(int nums[], int start, int end);
int Middle3(int nums[], int start, int end);
#endif //DATASTRUCTURE_SWAPSORT_H
