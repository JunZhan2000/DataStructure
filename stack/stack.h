#ifndef _STACK_H
#define _STACK_H

#include "BinaryTree/BinaryTree.h"

typedef  BinaryNodePtr StackElementType;
typedef int Position;
struct SNode {
    StackElementType *Data; /* 存储元素的数组 */
    Position Top;      /* 栈顶指针 */
    int MaxSize;       /* 堆栈最大容量 */
};
typedef struct SNode *Stack;

Stack CreateStack(int MaxSize);

int StackIsFull(Stack S);

int Push(Stack S, StackElementType X);

int StackIsEmpty(Stack S);

StackElementType Pop(Stack S);

#endif