//
// Created by 23276 on 2021/7/14.
//

#include "ThreadTree.h"
#include <stdio.h>
#include <stdlib.h>

// ����һ����ͷ������
ThreadTree CreateTree(ElementType data){
    ThreadTree Node = (ThreadTree)malloc(sizeof(ThreadNode));
    Node->data = data;
    Node->lchild = NULL;
    Node->rchild = NULL;
    Node->ltag = 0;
    Node->rtag = 0;

    return Node;
}


// ����һ����dataΪ������Ľڵ�
ThreadNodePtr CreateNode(ElementType data){
    ThreadNodePtr Node = (ThreadNodePtr)malloc(sizeof(ThreadNode));
    Node->data = data;
    Node->lchild = NULL;
    Node->rchild = NULL;
    Node->ltag = 0;
    Node->rtag = 0;

    return Node;
}


// ����һ���ڵ�
void Visit(ThreadNodePtr Node){
    printf("%d ", Node->data);
}


// ���������������㷨
// ���������������˳������������¼��һ�����ʵĽڵ㣩
// ע�����ģ�������������˵ݹ�ʵ�֣�����Ҫ�ڵݹ�����д���һ������pre���޸���
// C����ʵ������еㆪ�£�Ҫ�ýṹ��ָ���ָ�루C++Ӧ�ñȽϷ��㣩��������ѭ��ʵ�ָ����ʣ�����д�ˣ�
void CreateInThread(ThreadTree tree){
    ThreadNodePtr * pre = (ThreadNodePtr *)malloc(sizeof(ThreadNodePtr));   //�ڵݹ�����й��õı���
    *pre = NULL;
    if(tree != NULL){
        InThread(tree, pre);
        (*pre)->rchild = NULL;
        (*pre)->rtag = 1;  // �������һ���ڵ㣺û�к�̽ڵ�
    }
}


// �������������ݹ��㷨
void InThread(ThreadNodePtr Node, ThreadNodePtr *pre){
    if(Node == NULL){
        return;
    }
    InThread(Node->lchild, pre);    // ������������
    //���ʲ���������ǰ�ڵ�
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
    InThread(Node->rchild, pre);    // ������������
}


// �����������������
void InOrderTraverse(ThreadTree tree){
    printf("\n���������\n");
    if(tree == NULL){
        return;
    }
    ThreadNodePtr move = FirstNode(tree);
    while(move != NULL){
        Visit(move);
        move = NextNode(move);
    }
}


// ���������������е�һ�������ʵĽڵ�
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


// ���������������У�node�ĺ�̽ڵ�
ThreadNodePtr NextNode(ThreadNodePtr node){
    if(node == NULL){
        return NULL;
    }
    if(node->rtag == 0){
        // �ýڵ�û����������̽ڵ㣬�ֶ���ѯ
        return FirstNode(node->rchild);
    } else {
        // ֱ���������ҵ���̽ڵ�
        return node->rchild;
    }
}