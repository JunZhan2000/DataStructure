#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>


int main(void){
    BinaryTree Tree = CreateTree(1);     //������
    // ����������
    Tree->lchild = CreateNode(2);
    Tree->rchild = CreateNode(3);
    Tree->lchild->lchild = CreateNode(4);
    Tree->lchild->rchild = CreateNode(5);
    Tree->lchild->rchild->lchild = CreateNode(6);
    Tree->lchild->rchild->rchild = CreateNode(7);

    //����������ݹ飩
    printf("\n���������\n");
    PreOrderTraverseByRecursion(Tree);
    //����������ݹ飩
    printf("\n���������\n");
    InOrderTraverseByRecursion(Tree);
    //����������ݹ飩
    printf("\n���������\n");
    PostOrderTraverseByRecursion(Tree);

    //����������ǵݹ飩
    printf("\n���������\n");
    PreOrderTraverseByStack(Tree);
    //����������ǵݹ飩
    printf("\n���������\n");
    InOrderTraverseByRecursion(Tree);
    //����������ǵݹ飩
    printf("\n���������\n");
    PostOrderTraverseByRecursion(Tree);

    //��α���
    printf("\n��α�����\n");
    LevelOrderTraverse(Tree);
}