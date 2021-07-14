#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void){
    List L = CreateList();

    printf("List's Last: %d\n", L->Last);
    printf("L is a emtpy List: %d\n", IsEmpty(L));
    // DeleteList(L);
    Append(L, 1);
    Append(L, 2);
    Append(L, 3);
    Append(L, 4);
    PrintList(L);
    Insert(L, 1, -1);
    PrintList(L);
    Insert(L, 4, -2);
    PrintList(L);
    printf("Element 3: %d\n", Find(L, 3));
    DeleteElement(L, 2);
    PrintList(L);
    DeleteElement(L, 3);
    PrintList(L);
    SetElement(L, 1, -20);
    PrintList(L);

    return 0;
}


//创建一个容量为MAXSIZE的空表
List CreateList(){
    List L = (List)malloc(sizeof(struct ListStruct));   //给创建的表分配空间
    L->Last = -1;   //空表没有数据，Last值设为-1

    return L;
}

//判断一个表是否为空，若是空表则返回1，否则返回0
int IsEmpty(List L){
    if(L->Last == -1){
        return 1;   //Last值为-1，说明是空表
    } else{
        return 0;
    }
}

//输出表L的所有数据
void PrintList(List L){
    //打印表长度
    printf("List's length: %d\n", L->Last + 1);
    //打印表数据
    printf("List's data: ");
    for (int i = 0; i <= L->Last; i++){
        printf("%d ", L->Data[i]);
    }
    printf("\n");
}

//删除表L
void DeleteList(List L){
    free(L);
}

//删除表L在order位置上的数据
int DeleteElement(List L, Position order){
    if(order < 0 || order > L->Last){
        return ERROR;   //删除的元素的下标超出范围
    }

    //从后向前覆盖，以填补被删除的位置
    for (int i = order; i <= L->Last - 1; i++){
        L->Data[i] = L->Data[i + 1];
    }
    L->Last -= 1;

    return 0;
}

//修改表L在order位置上的数据为element
int SetElement(List L, Position order, ElementType element){
    if(order < 0 || order > L->Last){
        return ERROR;   //删除的元素的下标超出范围
    }
    L->Data[order] = element;

    return 0;
}

//查找表L在order位置上的数据元素
ElementType Find(List L, Position order){
    if(order < 0 || order > L->Last){
        return ERROR;   //查找的下标超出范围
    }
    return L->Data[order];
}

//在表L的末尾添加元素element
int Append(List L, ElementType element){
    if(L->Last >= MAXSIZE){
        return 1;   //表已经满了，返回1
    }

    L->Data[L->Last + 1] = element; //在尾部插入新元素
    L->Last += 1;   //尾部位置+1

    return 0;
}

//在表L的order位置上插入一个数据element
int Insert(List L, Position order, ElementType element){
    if(L->Last >= MAXSIZE){
        return 1;   //表已经满了，返回1
    }
    if(order < 0 || order >= MAXSIZE){
        return ERROR;   //插入的位置越界，返回ERROR
    }

    //逐个移动order后面的元素，注意从表尾开始
    for (int i = L->Last; i >= order; i--){
        L->Data[i + 1] = L->Data[i];
    }
    L->Data[order] = element;   //插入新元素
    L->Last += 1;

    return 0;
}