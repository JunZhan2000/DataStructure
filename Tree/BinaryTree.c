#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "stack.h"
#include "queue.h"

#define MAX_SIZE 100

// 创建一棵有头结点的树
BinaryTree CreateTree(ElementType data){
    BinaryNodePtr Node = (BinaryNodePtr)malloc(sizeof(BinaryNode));
    Node->data = data;
    Node->lchild = NULL;
    Node->rchild = NULL;

    return Node;
}


// 创建一个以data为数据域的节点
BinaryTree CreateNode(ElementType data){
    BinaryNodePtr Node = (BinaryNodePtr)malloc(sizeof(BinaryNode));
    Node->data = data;
    Node->lchild = NULL;
    Node->rchild = NULL;

    return Node;
}

// 访问一个节点
void Visit(BinaryNodePtr Node){
    printf("%d ", Node->data);
}


// 先序遍历二叉树（递归实现）
void PreOrderTraverseByRecursion(BinaryTree Tree){
    if(Tree == NULL){
        return;
    }
    Visit(Tree);
    PreOrderTraverseByRecursion(Tree->lchild);
    PreOrderTraverseByRecursion(Tree->rchild);
}


// 中序遍历二叉树（递归实现）
void InOrderTraverseByRecursion(BinaryTree Tree){
    if(Tree == NULL){
        return;
    }
    InOrderTraverseByRecursion(Tree->lchild);
    Visit(Tree);
    InOrderTraverseByRecursion(Tree->rchild);
}


// 后序遍历二叉树（递归实现）
void PostOrderTraverseByRecursion(BinaryTree Tree){
    if(Tree == NULL){
        return;
    }
    PostOrderTraverseByRecursion(Tree->lchild);
    PostOrderTraverseByRecursion(Tree->rchild);
    Visit(Tree);
}


// 先序遍历二叉树（非递归实现）
void PreOrderTraverseByStack(BinaryTree Tree){
    Stack stack = CreateStack(MAX_SIZE);
    BinaryNodePtr p = Tree, q = NULL;
    while (p || !StackIsEmpty(stack)){
        if (p){
            Push(stack, p);
            Visit(p);
            p = p->lchild;
        } else{
            q = Pop(stack);
            p = q->rchild;
        }
    }
}


// 中序遍历二叉树（非递归实现）
void InOrderTraverseByStack(BinaryTree Tree){
    Stack stack = CreateStack(MAX_SIZE);
    BinaryNodePtr p = Tree, q = NULL;
    while (p || !StackIsEmpty(stack)){
        if (p){
            //p不为空，要继续遍历左子树
            Push(stack, p);
            p = p->lchild;
        } else{
            //p为空，表示左子树已经结束了，要遍历自己了，然后再遍历右子树
            q = Pop(stack);
            Visit(q);
            p = q->rchild;
        }
    }
}


// 后序遍历二叉树（非递归实现）
void PostOrderTraverseByStack(BinaryTree Tree){
    Stack stack = CreateStack(MAX_SIZE);
    BinaryNodePtr p = Tree, q = NULL;
    while (p || !StackIsEmpty(stack)){
        if(p){
            //遍历左子树
            Push(stack, p);
            p = p->lchild;
        } else{
            q = Pop(stack);
            //遍历右子树
            if(q->rchild == NULL){
                //判断 有没有右子树或者是否访问完右子树，以决定继续访问右子树还是访问自身（q节点）
                Visit(q);
            } else{
                Push(stack, q);
            }
            p = q->rchild;
        }
    }
}


// 层次遍历二叉树（队列实现）
void LevelOrderTraverse(BinaryTree Tree){
    BinaryNodePtr temNode;
    Queue queue = CreateQueue();
    if(Tree == NULL){
        return;
    }
    Enqueue(queue, Tree);
    while (!QueueIsEmpty(queue)){
        temNode = Dequeue(queue);
        Visit(temNode);
        if(temNode->lchild != NULL){
            Enqueue(queue, temNode->lchild);
        }
        if(temNode->rchild != NULL){
            Enqueue(queue, temNode->rchild);
        }
    }
}
