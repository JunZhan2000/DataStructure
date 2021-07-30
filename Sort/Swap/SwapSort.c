//
// Created by 23276 on 2021/7/30.
//
#include <stdio.h>

// 交换nums数组中i和j的元素
void swap(int nums[], int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}


// 冒泡排序
void BubbleSort(int nums[], int length){
    int flag;   // 用于标记一趟排序中有没有出现交换
    for (int i = 0; i < length; i++){
        flag = 0;
        for (int j = 0; j < length-i-1; j++) {
            if (nums[j] > nums[j+1]){
                swap(nums, j, j+1);
                flag = 1;
            }
        }
        if (flag == 0){
            break;
        }
    }
}


// 选择主元
int Middle3(int nums[], int start, int end){
    int middle = (start + end) / 2;
    if (nums[start] > nums[middle]){
        swap(nums, start, middle);
    }
    if (nums[middle] > nums[end]){
        swap(nums, middle, end);
    }
    if (nums[start] > nums[middle]){
        swap(nums, start, middle);
    }
    swap(nums, middle, end-1);  //把主元放在待排序序列的最后面，便于划分两个子集

    return nums[end-1];
}


// 快速排序
void Quick_Sort(int nums[], int start, int end){
    if (start >= end) {  // 递归出口
        return;
    } else if (start == end -1 ){
        if (nums[start] > nums[end])
            swap(nums, start, end);
        return;
    } else {
        int pivot = Middle3(nums, start, end);  // 在首尾中 选择中位数作为主元
        int i = start+1, j = end-2;
        while (i <= j){
            while (nums[i] < pivot){
                i++;
            }
            while (nums[j] > pivot){
                j--;
            }
            if (i < j){
                swap(nums, i, j);
            }
        }
        swap(nums, end-1, i);
        Quick_Sort(nums, start, i-1);
        Quick_Sort(nums, i+1, end);
    }
}


void QuickSort(int nums[], int length){
    Quick_Sort(nums, 0, length-1);
}