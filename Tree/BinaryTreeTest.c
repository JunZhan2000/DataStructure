#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>


int main(void){
    BinaryTree Tree = CreateTree(1);     //创建树
    // 构建测试树
    Tree->lchild = CreateNode(2);
    Tree->rchild = CreateNode(3);
    Tree->lchild->lchild = CreateNode(4);
    Tree->lchild->rchild = CreateNode(5);
    Tree->lchild->rchild->lchild = CreateNode(6);
    Tree->lchild->rchild->rchild = CreateNode(7);

    //先序遍历（递归）
    printf("\n先序遍历：\n");
    PreOrderTraverseByRecursion(Tree);
    //中序遍历（递归）
    printf("\n中序遍历：\n");
    InOrderTraverseByRecursion(Tree);
    //后序遍历（递归）
    printf("\n后序遍历：\n");
    PostOrderTraverseByRecursion(Tree);

    //先序遍历（非递归）
    printf("\n先序遍历：\n");
    PreOrderTraverseByStack(Tree);
    //中序遍历（非递归）
    printf("\n中序遍历：\n");
    InOrderTraverseByRecursion(Tree);
    //后序遍历（非递归）
    printf("\n后序遍历：\n");
    PostOrderTraverseByRecursion(Tree);

    //层次遍历
    printf("\n层次遍历：\n");
    LevelOrderTraverse(Tree);
}