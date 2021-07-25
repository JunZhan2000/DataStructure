//
// Created by 23276 on 2021/7/25.
//

#ifndef DATASTRUCTURE_BINARYSEARCHTREE_H
#define DATASTRUCTURE_BINARYSEARCHTREE_H

#define Error -1;

typedef int ElementType;

typedef struct BSTNode{
    ElementType data;       // 节点的数据
    struct BSTNode * left;  // 左子树
    struct BSTNode * right; // 右子树
} BSTNode, * BinarySearchTree;


// 以下算法均可用递归和循环实现，但实现区别不大，不再分别实现
ElementType FindMax(BinarySearchTree T);    // 查找树上最大的元素
ElementType FindMin(BinarySearchTree T);    // 查找树上最小的元素
BinarySearchTree Find(BinarySearchTree T, ElementType data);    // 查找节点
BinarySearchTree Insert(BinarySearchTree T, ElementType data);  // 插入节点
BinarySearchTree Delete(BinarySearchTree T, ElementType data);  // 删除节点

#endif //DATASTRUCTURE_BINARYSEARCHTREE_H
