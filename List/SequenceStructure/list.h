#ifndef _List_H

#define MAXSIZE 100
#define ERROR -1

/* 数据结构 */
typedef int ElementType;    //基本数据类型
typedef int Position;       //数据位置
typedef struct ListStruct{  //线性表结构体
    ElementType Data[MAXSIZE];  //存放数据的顺序结构
    int Last;   //记录表最后一个数据的位置
} * List;   //线性表指针


/* 操作的集合 */
List CreateList();  //创建一个容量为MAXSIZE的空表
int IsEmpty(List L);    //判断一个表是否为空
void DeleteList(List L);    //删除表L
int DeleteElement(List L, Position order);  //删除表L在order位置上的数据
int SetElement(List L, Position order, ElementType element);    //修改表L在order位置上的数据为element
ElementType Find(List L, Position order);    //查找表L在order位置上的数据元素
int Append(List L, ElementType element);    //在表L的末尾添加元素element
int Insert(List L, Position order, ElementType element); //在表L的order位置上插入一个数据element
void PrintList(List L);  //输出表L的所有数据

#endif // !_List_H