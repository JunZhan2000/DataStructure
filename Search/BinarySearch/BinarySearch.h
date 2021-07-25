//
// Created by 23276 on 2021/7/25.
//

#ifndef DATASTRUCTURE_BINARYSEARCH_H
#define DATASTRUCTURE_BINARYSEARCH_H

#define MAX_LENGTH 100

// 顺序表的数据结构
typedef int KeyType;
typedef struct {
    KeyType keys[MAX_LENGTH];
    int length;
}SSTableStruct, * SSTable;


SSTable GetATestTable();    // 创建一个测试表
int BinarySearch(SSTable T, KeyType key); // 二叉查找算法

#endif //DATASTRUCTURE_BINARYSEARCH_H
