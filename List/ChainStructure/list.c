#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void){
    List L = CreateList();

    PrintList(L);
    printf("L is a emtpy List: %d\n", IsEmpty(L));
    PrintList(L);
    Append(L, 1);
    Append(L, 2);
    Append(L, 3);
    Append(L, 4);
    PrintList(L);
    Position p0 = (Position)malloc(sizeof(struct Node));
    p0->Element = -999;
    Position p1 = Find(L, 1);
    Position p2 = Find(L, 4);
    Position p3 = Find(L, 0);
    Position p4 = FindPrevious(L, p1);
    Position p5 = FindPrevious(L, p2);
    Position p6 = FindPrevious(L, p0);
    Insert(L, p1, -1);
    PrintList(L);
    Insert(L, p2, -2);
    PrintList(L);
    Insert(L, p3, -3);
    PrintList(L);
    SetElement(L, p1, -10);
    PrintList(L);
    SetElement(L, p0, -10);
    PrintList(L);
    Position firstP = Find(L, -1);
    Position p7 = Find(L, -3);
    DeleteElement(L, firstP);
    PrintList(L);
    DeleteElement(L, p7);
    PrintList(L);
    DeleteElement(L, p0);
    PrintList(L);

    DeleteList(L);
    
    return 0;
}


//创建一个容量为MAXSIZE的空表
List CreateList(){
    List L = (List)malloc(sizeof(struct ListStruct)); //创建表
    L->Length = 0;
    L->First = NULL;

    return L;
}

//判断一个表是否为空，若是空表则返回1，否则返回0
int IsEmpty(List L){
    if(L->Length == 0){
        return 1;
    }
    return 0;
}

//输出表L的所有数据
void PrintList(List L){
    printf("List's length: %d\n", L->Length);
    printf("List's data: ");
    PtrToNode mov = L->First;
    while (mov != NULL){
        printf("%d ", mov->Element);    //打印当前节点的元素
        mov = mov->Next;    //移动至后继节点
    }
    printf("\n");
}

//删除表L
void DeleteList(List L){
    if (L->First == NULL){
        //L为空表，则直接释放表结构体
        free(L);
        return;
    }

    Position mov = L->First;
    Position movNext = mov->Next;
    while (movNext != NULL){
        free(mov);
        mov = movNext;
        movNext = mov->Next;
    }
    free(mov);
    free(L);
}

//删除表L的P节点
int DeleteElement(List L, Position P){
    if(P == NULL){
        return 1;
    }
    if(L->First == P){  //如果P为首节点
        L->First = P->Next;
        free(P);
        L->Length--;
        return 0;
    }

    Position previousNode = FindPrevious(L, P); //寻找P的前驱节点
    if(previousNode == NULL){
        return 1;
    }
    previousNode->Next = P->Next;
    free(P);
    L->Length--;
    return 0;
}

//修改表L在P节点上的数据为element
int SetElement(List L, Position P, ElementType element){
    if(P == NULL) {
        return 1;
    }

    Position mov = L->First;
    while (mov != NULL && mov != P){    //遍历链表寻找节点P
        mov = mov->Next;
    }
    if(mov == NULL){    //没有找到则直接返回
        return 1;
    }
    mov->Element = element; //找到节点则修改其值
    return 0;
}

//查找表L上数据元素为element的节点
Position Find(List L, ElementType element){
    if(L->First == NULL){
        return NULL;    //如果L为空表，直接返回空
    }
    Position mov = L->First;
    while (mov != NULL && mov->Element != element){
        mov = mov->Next;
    }
    return mov; //如果找到对应节点，返回该节点；否则返回空指针
}

//查找表L在P位置上的前驱节点
Position FindPrevious(List L, Position P){
    if(P == NULL) {
        return NULL;
    }

    Position mov = L->First;
    while (mov->Next != NULL && mov->Next != P){
        mov = mov->Next;    //遍历链表，寻找前驱节点
    }

    if(mov->Next == NULL){
        return NULL;    //没有找到则返回空
    }
    return mov;
}

//在表L的末尾添加元素element
int Append(List L, ElementType element){
    if (L->First == NULL){//L是空表，直接插入
        L->First = (PtrToNode)malloc(sizeof(struct Node));
        //给新插入的节点赋值
        L->First->Element = element;
        L->First->Next = NULL;
        L->Length += 1;
        return 0;
    }
    
    PtrToNode mov = L->First;
    //使mov移动至尾节点
    while (mov->Next != NULL){
        mov = mov->Next;
    }
    mov->Next = (PtrToNode)malloc(sizeof(struct Node));
    //给新插入的节点赋值
    mov->Next->Element = element;
    mov->Next->Next = NULL;
    L->Length += 1;

    return 0;
}

//在表L的P位置上插入一个数据element
int Insert(List L, Position P, ElementType element){
    //创建新节点
    Position tempNode = (Position)malloc(sizeof(struct Node));
    tempNode->Element = element;
    
    if(P == L->First){  //如果P是表的首节点，直接插入
        L->First = tempNode;
        tempNode->Next = P;
        L->Length++;
        return 0;
    }

    Position previousNode = FindPrevious(L, P);   //查找P在L上的前驱节点
    if(previousNode == NULL){//若在L中没有P的前驱节点，则在尾部插入
        Append(L, element);
        return 0;
    }

    //插入新节点
    tempNode->Next = P;
    previousNode->Next = tempNode;
    L->Length++;

    return 0;
}