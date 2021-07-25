//
// Created by 23276 on 2021/7/25.
//

#include "BinarySearch.h"
#include <stdio.h>

int main(void){
    SSTable T = GetATestTable();    // 测试表
    printf("%d\n", BinarySearch(T, 8));
    printf("%d\n", BinarySearch(T, 20));
    printf("%d\n", BinarySearch(T, 13));
    return 0;
}