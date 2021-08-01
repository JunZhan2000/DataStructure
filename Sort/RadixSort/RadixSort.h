//
// Created by 23276 on 2021/8/1.
//

#ifndef DATASTRUCTURE_RADIXSORT_H
#define DATASTRUCTURE_RADIXSORT_H


// 默认序列中数字位数最多为4位，方便测试，也可以写个循环计算得到
#define DigitNum 4
#define Radix 10    // 设置基数为10

// 桶中链表的元素节点
typedef struct Node{
    int num;
    struct Node * next;
} Node, * Ptr2Node;
// 桶头的节点
typedef struct BucketHead{
    Ptr2Node head, tail;
} BucketHead;
typedef BucketHead Bucket[Radix];     // 存放链表的桶


// 获取num的第D位
int GetDigit(int num, int Di);
// 基数排序
void RadixSort(int nums[], int length);


#endif //DATASTRUCTURE_RADIXSORT_H
