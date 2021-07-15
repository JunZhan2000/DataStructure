//
// Created by 23276 on 2021/7/14.
//

#ifndef DATASTRUCTURE_THREADTREE_H
#define DATASTRUCTURE_THREADTREE_H


typedef int ElementType;
// 二叉树的节点
typedef struct ThreadNode{
    ElementType data;   // 数据域
    struct ThreadNode *lchild, * rchild;    // 左右子节点
    int ltag, rtag;     //标记左右子节点是否线索化
} ThreadNode, * ThreadTree, * ThreadNodePtr;


// 创建一棵有头结点的树
ThreadTree CreateTree(ElementType data);
// 创建一个以data为数据域的节点
ThreadNodePtr CreateNode(ElementType data);
// 访问一个节点
void Visit(ThreadNodePtr Node);
// 二叉树线索化主算法
void CreateInThread(ThreadTree tree);
// 二叉树线索化
void InThread(ThreadNodePtr Node, ThreadNodePtr * pre);
// 中序遍历线索二叉树
void InOrderTraverse(ThreadTree tree);
// 求二叉树中序遍历中第一个被访问的节点
ThreadNodePtr FirstNode(ThreadTree tree);
// 求二叉树中序遍历中，node的后继节点
ThreadNodePtr NextNode(ThreadNodePtr node);


#endif //DATASTRUCTURE_THREADTREE_H