//
// Created by 23276 on 2021/7/25.
//

#include "BinarySearchTree.h"
#include <stdio.h>

void FindTest(BinarySearchTree T, ElementType data){
    BinarySearchTree findNode = Find(T, data);
    if (!findNode){
        printf("未找到: %d\n", data);
    }else if (findNode->data == data){
        printf("已找到: %d\n", data);
    } else {
        printf("查找错误: %d\n", data);
    }

}

int main(void){
    BinarySearchTree T = NULL;
    T = Insert(T, 13);
    T = Insert(T, 2);
    T = Insert(T, 9);
    T = Insert(T, 10);
    T = Insert(T, 1);
    T = Insert(T, 20);
    T = Insert(T, 15);
    T = Insert(T, 4);
    T = Insert(T, 19);

    printf("T的最大值：%d\n", FindMax(T));
    printf("T的最小值：%d\n", FindMin(T));
    FindTest(T, 13);
    FindTest(T, 20);
    FindTest(T, 99);

    Delete(T, 99);
    Delete(T, 13);
    Delete(T, 15);

    return 0;
}