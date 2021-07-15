//
// Created by 23276 on 2021/7/14.
//

#include "ThreadTree.h"
#include <stdio.h>
#include <stdlib.h>

// 创建一棵有头结点的树
ThreadTree CreateTree(ElementType data){
    ThreadTree Node = (ThreadTree)malloc(sizeof(ThreadNode));
    Node->data = data;
    Node->lchild = NULL;
    Node->rchild = NULL;
    Node->ltag = 0;
    Node->rtag = 0;

    return Node;
}


// 创建一个以data为数据域的节点
ThreadNodePtr CreateNode(ElementType data){
    ThreadNodePtr Node = (ThreadNodePtr)malloc(sizeof(ThreadNode));
    Node->data = data;
    Node->lchild = NULL;
    Node->rchild = NULL;
    Node->ltag = 0;
    Node->rtag = 0;

    return Node;
}


// 访问一个节点
void Visit(ThreadNodePtr Node){
    printf("%d ", Node->data);
}


// 二叉树线索化主算法
// 中序遍历二叉树，顺便线索化（记录上一个访问的节点）
// 注意这里：模仿王道书上用了递归实现，但是要在递归进程中传递一个参数pre并修改它
// C语言实现这个有点啰嗦，要用结构体指针的指针（C++应该比较方便）。或许用循环实现更合适（懒得写了）
void CreateInThread(ThreadTree tree){
    ThreadNodePtr * pre = (ThreadNodePtr *)malloc(sizeof(ThreadNodePtr));   //在递归进程中共用的变量
    *pre = NULL;
    if(tree != NULL){
        InThread(tree, pre);
        (*pre)->rchild = NULL;
        (*pre)->rtag = 1;  // 处理最后一个节点：没有后继节点
    }
}


// 二叉树线索化递归算法
void InThread(ThreadNodePtr Node, ThreadNodePtr *pre){
    if(Node == NULL){
        return;
    }
    InThread(Node->lchild, pre);    // 线索化左子树
    //访问并线索化当前节点
    Visit(Node);
    if(Node->lchild == NULL){
        if(pre == NULL){
            Node->lchild = NULL;
        } else{
            Node->lchild = *pre;
        }
        Node->ltag = 1;
    }
    if(*pre != NULL && (*pre)->rchild == NULL){
        (*pre)->rchild = Node;
        (*pre)->rtag = 1;
    }
    *pre = Node;
    InThread(Node->rchild, pre);    // 线索化右子树
}


// 中序遍历线索二叉树
void InOrderTraverse(ThreadTree tree){
    printf("\n中序遍历：\n");
    if(tree == NULL){
        return;
    }
    ThreadNodePtr move = FirstNode(tree);
    while(move != NULL){
        Visit(move);
        move = NextNode(move);
    }
}


// 求二叉树中序遍历中第一个被访问的节点
ThreadNodePtr FirstNode(ThreadTree tree){
    if (tree == NULL){
        return NULL;
    }
    ThreadNodePtr move = tree;
    while (move->ltag == 0){
        move = move->lchild;
    }
    return move;
}


// 求二叉树中序遍历中，node的后继节点
ThreadNodePtr NextNode(ThreadNodePtr node){
    if(node == NULL){
        return NULL;
    }
    if(node->rtag == 0){
        // 该节点没有线索化后继节点，手动查询
        return FirstNode(node->rchild);
    } else {
        // 直接由线索找到后继节点
        return node->rchild;
    }
}