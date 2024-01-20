#include "queue.h"
#include <stdbool.h>
// 初始化队列
void initQueue(Queue *queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

// 检查队列是否为空
bool isQueueEmpty(Queue *queue) {
    return queue->size == 0;
}

// 检查队列是否已满
bool isQueueFull(Queue *queue) {
    return queue->size == QUEUE_CAPACITY;
}

// 入队操作
bool enQueue(Queue *queue, QueueElementType element) {
    if (isQueueFull(queue)) {
        return false;
    }
    queue->rear = (queue->rear + 1) % QUEUE_CAPACITY;
    queue->elements[queue->rear] = element;
    queue->size++;
    return true;
}

// 出队操作
bool deQueue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        return false;
    }
    queue->front = (queue->front + 1) % QUEUE_CAPACITY;
    queue->size--;
    return true;
}

// 查看队首元素
QueueElementType peekQueue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        return (QueueElementType){-1,-1};  // 返回指示空队列的特殊值
    }
    return queue->elements[queue->front];
}

// 重置队列
void resetQueue(Queue *queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

