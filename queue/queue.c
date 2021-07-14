#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


//创建一个空队列
Queue CreateQueue(){
    Queue queue = (Queue)malloc(sizeof(struct Queue));

    queue->MaxLength = QueueLength;
    queue->first = 0;
    queue->last = 0;

    return queue;
}


//判断一个队列是否为空
int QueueIsEmpty(Queue Q){
    if(Q->first == Q->last){
        //队列中没有元素
        return 1;
    }
    else{
        return 0;
    }
}


//判断一个队列是否已满
int QueueIsFull(Queue Q){
    if(Q->first == ( (Q->last+1) % Q->MaxLength) ){
        //队列已满
        return 1;
    }
    else{
        return 0;
    }
}


//一个元素入队
void Enqueue(Queue Q, QueueDataType value){
    if( QueueIsFull(Q) ){
        //队列已满，不再入队
        printf("Queue is full!\n");
        return;
    }
    Q->data[Q->last] = value;   //元素入队
    Q->last = (Q->last + 1) % QueueLength;
}


//一个元素出队
QueueDataType Dequeue(Queue Q){
    if( QueueIsEmpty(Q) ){
        //队列中没有元素，不出队
        return NULL;
    }

    QueueDataType temp = Q->data[Q->first];    //记录队首的值
    Q->first = (Q->first + 1) % Q->MaxLength;
    return temp;
}
