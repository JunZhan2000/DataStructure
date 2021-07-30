//
// Created by 23276 on 2021/7/29.
//

#ifndef DATASTRUCTURE_INSERTSORT_H
#define DATASTRUCTURE_INSERTSORT_H


// 交换nums数组中i和j的元素
void swap(int nums[], int i, int j);
// 直接插入排序
void InsertSort(int nums[], int length);
// 折半插入排序
void BinInsertSort(int nums[], int length);
// 希尔排序
void ShellInsert(int nums[], int length, int hop);
void ShellSort(int nums[], int length);



#endif //DATASTRUCTURE_INSERTSORT_H
