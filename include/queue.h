#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define QUEUE_CAPACITY 100  // 定义队列的固定容量
#define QUEUE_EMPTY -1      // 空队列时的返回值



typedef struct {
    int page;
    int block
} LossInfoType;
typedef LossInfoType QueueElementType;  // 队列中元素的类型

typedef struct {
    QueueElementType elements[QUEUE_CAPACITY]; // 队列元素数组
    int front;  // 队首索引
    int rear;   // 队尾索引
    int size;   // 队列当前大小
} Queue;

// 队列操作函数原型
void initQueue(Queue *queue);
bool isQueueEmpty(Queue *queue);
bool isQueueFull(Queue *queue);
bool enQueue(Queue *queue, QueueElementType element);
bool deQueue(Queue *queue);
void resetQueue(Queue *queue);
QueueElementType peekQueue(Queue *queue);

#endif // QUEUE_H
