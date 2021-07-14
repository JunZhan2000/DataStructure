/* 数组实现的栈 */
#include "stack.h"
 
Stack CreateStack( int MaxSize )
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}
 
int IsFull( Stack S )
{   
    if(S->Top == S->MaxSize-1) {
        return 1;
    } else{
        return 0;
    }
}
 
int Push( Stack S, ElementType X )
{
    if ( IsFull(S) ) {
        printf("堆栈满");
        return 0;
    }
    else {
        S->Data[++(S->Top)] = X;
        return 1;
    }
}
 
int IsEmpty( Stack S )
{
    if(S->Top == -1) {
        return 1;
    } else{
        return 0;
    }
}
 
ElementType Pop( Stack S )
{
    if ( IsEmpty(S) ) {
        printf("堆栈空");
        return -99999; /* ERROR是ElementType的特殊值，标志错误 */
    }
    else 
        return ( S->Data[(S->Top)--] );
}