#include "Queue.h"
#include "Boolean.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void createQueue(Queue* q, int capacity) {
    if (capacity < 1) {
        printf("ERROR: KAPASITAS INVALID\n");
        return;
    }
    q->capacity = capacity;
    q->size = 0;
    q->front = NULL;
    q->rear = NULL;
}

void enQueue(Queue* q, LinkedListNode* node) {
    if (isQueueFull(q)) {
        printf("ERROR: ANTRIAN PENUH!\n");
        return;
    }
    
    node->next = NULL;
    if (isQueueEmpty(q)) {
        q->front = node;
        q->rear =  node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
    q->size += 1;
}

void deQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("ERROR: ANTRIAN KOSONG!\n");
        return;
    }
    LinkedListNode* newFront = q->front->next;
    q->front->next = NULL;
    free(q->front);
    q->front = newFront; 
    q->size -= 1;

    // if before dequeue size = 1, front = rear, then update rear too
    if (q->front == NULL) {
        q->rear = NULL;
    }
}

void freeQueue(Queue* q) {
    while (q->front != NULL) {
        deQueue(q);
    }
}

boolean isQueueEmpty(const Queue* q) {
    return q->size == 0;
}

boolean isQueueFull(const Queue* q) {
    return q->size == q->capacity;
}