/* 数组实现的栈 */

typedef char ElementType;
typedef int Position;
struct SNode {
    ElementType *Data; /* 存储元素的数组 */
    Position Top;      /* 栈顶指针 */
    int MaxSize;       /* 堆栈最大容量 */
};
typedef struct SNode *Stack;

Stack CreateStack(int MaxSize);

int IsFull(Stack S);

int Push(Stack S, ElementType X);

int IsEmpty(Stack S);

ElementType Pop(Stack S);