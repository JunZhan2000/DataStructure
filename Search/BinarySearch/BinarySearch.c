//
// Created by 23276 on 2021/7/25.
//

#include "BinarySearch.h"
#include <stdlib.h>

// 创建一个测试表
SSTable GetATestTable(){
    SSTable T = (SSTable) malloc(sizeof(SSTableStruct));

    T->keys[0] = 1;
    T->keys[1] = 2;
    T->keys[2] = 4;
    T->keys[3] = 9;
    T->keys[4] = 10;
    T->keys[5] = 13;
    T->keys[6] = 15;
    T->keys[7] = 19;
    T->keys[8] = 20;
    T->length = 9;

    return T;
}


// 二叉查找算法
int BinarySearch(SSTable T, KeyType key){
    int start = 0, end = T->length-1;
    int mid;

    while (start <= end){
        mid = (start + end) / 2;
        if (T->keys[mid] == key){
            return mid;
        } else if (T->keys[mid] > key){
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return -1;
}