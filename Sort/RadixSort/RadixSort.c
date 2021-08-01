//
// Created by 23276 on 2021/8/1.
//

#include "RadixSort.h"
#include <stdlib.h>


// 获取num的第D位
int GetDigit(int num, int Di){
    for (int i = 0; i < Di-1; i++){
        num /= Radix;
    }
    return num % Radix;
}


// 基数排序
void RadixSort(int nums[], int length){
    Bucket bucket;
    Ptr2Node List = NULL, tmp, mov;
    int DiValue;    // Di位的数值

    // 初始化桶的每个桶项为空
    for (int i = 0; i < Radix; i++){
        bucket[i].head = NULL;
        bucket[i].tail = NULL;
    }
    // 将数组中的元素逆序存放在List中（逆序是因为方便写代码）
    for (int i = 0; i < length; i++){
        tmp = (Ptr2Node) malloc(sizeof(Node));
        tmp->num = nums[i];
        tmp->next = List;
        List = tmp;
    }

    for (int Di = 1; Di <= DigitNum; Di++){// 每一次循环处理一位
        // 把List中的元素分配到桶的各个桶项
        mov = List;
        while (mov != NULL){
            DiValue = GetDigit(mov->num, Di);   // 获取第Di位的元素
            tmp = mov; mov = mov->next; // 记录当前节点，mov指向下一个
            tmp->next = NULL;
            if (bucket[DiValue].head == NULL){
                // DiValue桶项为空
                bucket[DiValue].head = bucket[DiValue].tail = tmp;
            } else {
                // DiValue桶项不为空，插入表尾（遍历桶的时候则从表头开始，保证稳定性）
                bucket[DiValue].tail->next = tmp;
                bucket[DiValue].tail = tmp;
            }
        }
        // 收集桶中的元素
        // 逆序是因为方便List把各个链表串起来
        List = NULL;
        for (int i = Radix-1; i >= 0; i--){
            if (bucket[i].head) {
                bucket[i].tail->next = List;
                List = bucket[i].head;
                bucket[i].head = bucket[i].tail = NULL;   // 清空桶
            }
        }
    }

    // 把List中已排好序的元素输出到nums中，并释放List链表的空间
    mov = List;
    for (int i = 0; i < length; i++){
        tmp = mov;
        mov = mov->next;
        nums[i] = tmp->num;
        free(tmp);
    }
}