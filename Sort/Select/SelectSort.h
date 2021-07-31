//
// Created by 23276 on 2021/7/31.
//

#ifndef DATASTRUCTURE_SELECTSORT_H
#define DATASTRUCTURE_SELECTSORT_H


// 交换nums数组中i和j的元素
void swap(int nums[], int i, int j);
// 简单选择排序
void SelectSort(int nums[], int length);
// 堆排序
void HeapSort(int nums[], int length);
// 建立堆
void BuildHeap(int nums[], int length);
// 调整堆
void AdjustHeap(int nums[], int root, int end);


#endif //DATASTRUCTURE_SELECTSORT_H
