//
// Created by 23276 on 2021/8/1.
//


#include "RadixSort.h"
#include <stdio.h>


void OutputNums(int nums[], int length){
    for(int i = 0; i < length; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
}


int main(void){
    int nums[8] = {494, 8, 265, 9701, 763, 3, 1123, 49};
    int length = 8;
    printf("未排序：");
    OutputNums(nums, length);

    RadixSort(nums, length);
    printf("基数排序：");
    OutputNums(nums, length);


    return  0;
}