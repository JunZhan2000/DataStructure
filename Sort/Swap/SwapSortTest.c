//
// Created by 23276 on 2021/7/30.
//


#include "SwapSort.h"
#include <stdio.h>


void OutputNums(int nums[], int length){
    for(int i = 0; i < length; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
}


int main(void){
    int nums[8] = {49, 38, 65, 97, 76, 13, 27, 49};
    int length = 8;
    printf("未排序：");
    OutputNums(nums, length);

    BubbleSort(nums, length);
    printf("冒泡排序：");
    OutputNums(nums, length);

    int nums2[8] = {49, 38, 65, 97, 76, 13, 27, 49};
    QuickSort(nums2, length);
    printf("快速排序：");
    OutputNums(nums2, length);

    return  0;
}