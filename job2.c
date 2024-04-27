#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
typedef struct {
    int jobId;
    int length; 
} PrintJob;
typedef struct {
    PrintJob jobs[MAX_SIZE];
    int front, rear;
} PrinterQueue;
void initQueue(PrinterQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}
int isEmpty(PrinterQueue *queue) {
    return queue->front == -1;
}
int isFull(PrinterQueue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}
void enqueue(PrinterQueue *queue, PrintJob job) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot add more jobs.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->jobs[queue->rear] = job;
}
PrintJob dequeue(PrinterQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No jobs to dequeue.\n");
        PrintJob emptyJob = {-1, -1};
        return emptyJob;
    }
    PrintJob job = queue->jobs[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return job;
}

int main() {
    PrinterQueue queue;
    initQueue(&queue);
    enqueue(&queue, (PrintJob){1, 5}); 
    enqueue(&queue, (PrintJob){2, 3});
    enqueue(&queue, (PrintJob){3, 7}); 
    PrintJob job = dequeue(&queue);
    printf("Dequeued Job ID: %d, Length: %d\n", job.jobId, job.length);
    job = dequeue(&queue);
    printf("Dequeued Job ID: %d, Length: %d\n", job.jobId, job.length);
    job = dequeue(&queue);
    printf("Dequeued Job ID: %d, Length: %d\n", job.jobId, job.length);
    job = dequeue(&queue);
    printf("Dequeued Job ID: %d, Length: %d\n", job.jobId, job.length);

    return 0;
}