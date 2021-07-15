//
// Created by 23276 on 2021/7/15.
//

#include "ThreadTree.h"
#include <stdio.h>


int main(void){
    ThreadTree tree = CreateTree(1);     //������
    // ����������
    tree->lchild = CreateNode(2);
    tree->rchild = CreateNode(3);
    tree->lchild->lchild = CreateNode(4);
    tree->lchild->rchild = CreateNode(5);
    tree->lchild->rchild->lchild = CreateNode(6);
    tree->lchild->rchild->rchild = CreateNode(7);

    CreateInThread(tree);   //������������
    InOrderTraverse(tree);  //��������������
}