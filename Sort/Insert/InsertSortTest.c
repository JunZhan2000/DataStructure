//
// Created by 23276 on 2021/7/29.
//

#include "InsertSort.h"
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

    InsertSort(nums, length);
    printf("插入排序：");
    OutputNums(nums, length);

    int nums2[8] = {49, 38, 65, 97, 76, 13, 27, 49};
    BinInsertSort(nums2, length);
    printf("折半插入排序：");
    OutputNums(nums2, length);

    int nums3[8] = {49, 38, 65, 97, 76, 13, 27, 49};
    ShellSort(nums3, length);
    printf("希尔排序：");
    OutputNums(nums3, length);

    return  0;
}