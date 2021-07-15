#ifndef _QUEUE_H
#define _QUEUE_H

#define QueueLength 100

#include "BinaryTree/BinaryTree.h"

typedef BinaryNodePtr QueueDataType;

//为了便于判断队空与队满，我们将last视为队尾后的一个元素，在队列还剩一个元素没有被占据时即视作队满
typedef struct Queue{
    int MaxLength;
    int first;      //队列中最先进队的元素下标
    int last;       //队列中最后进队的元素的后面那个元素的下标
    QueueDataType data[QueueLength];
} *Queue;   //循环数组实现的队列

Queue CreateQueue();                          //创建一个空队列
int QueueIsEmpty(Queue Q);                         //判断一个队列是否为空
int QueueIsFull(Queue Q);                          //判断一个队列是否已满
void Enqueue(Queue Q, QueueDataType value);   //一个元素入队
QueueDataType Dequeue(Queue Q);               //一个元素出队


#endif