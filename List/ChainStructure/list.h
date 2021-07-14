#ifndef _List_H
//线性表的链式结构实现

#define MAXSIZE 100
#define ERROR -1

/* 数据结构 */
typedef int ElementType;    //基本数据类型
typedef struct Node{    //线性表结构体
    ElementType Element;   //存储该节点的数据
    struct Node *Next;  //指向下一个节点
} * PtrToNode;   //线性表指针
typedef struct ListStruct{
    int Length;         //表长
    PtrToNode First;    //第一个节点
} * List;   //表类型
typedef PtrToNode Position; //数据位置

/* 操作的集合 */
List CreateList();      //创建一个容量为MAXSIZE的空表
int IsEmpty(List L);    //判断一个表是否为空
void DeleteList(List L);    //删除表L
int DeleteElement(List L, Position P);  //删除表L的P节点
int SetElement(List L, Position P, ElementType element);    //修改表L上P节点的数据为element
Position Find(List L, ElementType element);    //查找表L上数据元素为element的节点
Position FindPrevious(List L, Position P);    //查找表L上P节点的前驱节点
int Append(List L, ElementType element);    //在表L的末尾添加元素element
int Insert(List L, Position P, ElementType element); //在表L的P节点前插入一个数据element
void PrintList(List L);  //输出表L的所有数据

#endif // !_List_H