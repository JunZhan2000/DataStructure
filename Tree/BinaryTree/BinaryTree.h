#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

typedef int ElementType;
// 二叉树的节点
typedef struct BinaryNode{
    ElementType data;   // 数据域
    struct BinaryNode *lchild, * rchild;    // 左右子节点
} BinaryNode, * BinaryTree, * BinaryNodePtr;


// 创建一棵有头结点的树
BinaryTree CreateTree(ElementType data);
// 创建一个以data为数据域的节点
BinaryNodePtr CreateNode(ElementType data);
// 访问一个节点
void Visit(BinaryNodePtr Node);
// 先序遍历二叉树（递归实现）
void PreOrderTraverseByRecursion(BinaryTree Tree);
// 中序遍历二叉树（递归实现）
void InOrderTraverseByRecursion(BinaryTree Tree);
// 后序遍历二叉树（递归实现）
void PostOrderTraverseByRecursion(BinaryTree Tree);
// 先序遍历二叉树（非递归实现）
void PreOrderTraverseByStack(BinaryTree Tree);
// 中序遍历二叉树（非递归实现）
void InOrderTraverseByStack(BinaryTree Tree);
// 后序遍历二叉树（非递归实现）
void PostOrderTraverseByStack(BinaryTree Tree);
// 层次遍历二叉树（队列实现）
void LevelOrderTraverse(BinaryTree Tree);

#endif // !_BinaryTree_H