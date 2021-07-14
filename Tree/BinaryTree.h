#ifndef _BinaryTree_H

#define ElementType int

// 二叉树的节点
typedef struct BinaryNode{
    ElementType data;   // 数据域
    struct BinaryNode *lchild, * rchild;    //左右子节点
} BinaryNode, * BinaryTree;



#endif // !_BinaryTree_H