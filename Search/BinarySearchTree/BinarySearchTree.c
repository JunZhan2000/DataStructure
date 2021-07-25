//
// Created by 23276 on 2021/7/25.
//

#include "BinarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

// 查找树上最大的元素
ElementType FindMax(BinarySearchTree T){
    if (T == NULL){
        return Error;
    }
    BinarySearchTree mov = T;
    while (mov->right != NULL){
        mov = mov->right;
    }

    return mov->data;
}


// 查找树上最小的元素
ElementType FindMin(BinarySearchTree T){
    if (T == NULL){
        printf("树为空！\n");
        return Error;
    }
    BinarySearchTree mov = T;
    while (mov->left != NULL){
        mov = mov->left;
    }

    return mov->data;
}


// 查找节点
BinarySearchTree Find(BinarySearchTree T, ElementType data){
    if (T == NULL){
        printf("未找到！\n");
        return NULL;
    }

    if (T->data == data){
        return T;
    } else if (T->data > data){
        return Find(T->left, data);
    } else {
        return Find(T->right, data);
    }
}


// 插入节点
BinarySearchTree Insert(BinarySearchTree T, ElementType data){
    if (T == NULL){
        BinarySearchTree newTree = (BinarySearchTree) malloc(sizeof(BSTNode));
        newTree->data = data;
        newTree->left = NULL;
        newTree->right = NULL;
        return newTree;
    }
    if (T->data == data){
        printf("data已存在！\n");
    } else if (T->data > data){
        T->left = Insert(T->left, data);
    } else {
        T->right = Insert(T->right, data);
    }

    return T;
}


// 删除节点
BinarySearchTree Delete(BinarySearchTree T, ElementType data){
    if (T == NULL){
        printf("树中没有%d！\n", data);
        return NULL;
    }

    if (T->data > data){
        T->left = Delete(T->left, data);
    } else if(T->data < data){
        T->right = Delete(T->right, data);
    } else{
        // 找到要被删除的节点
        if(T->left && T->right){
            // 左右节点同时存在，则用左子树的最大值替代当前节点(也可用右子树的最小值)
            ElementType leftMax = FindMax(T->left);
            T->data = leftMax;
            T->left = Delete(T->left, leftMax);
        } else{
            // 左右节点存在一个 或者均不存在
            BinarySearchTree tmp = T;
            if (T->left){
                T = T->left;
            } else{
                T = T->right;
            }
            free(tmp);
        }
    }

    return T;
}