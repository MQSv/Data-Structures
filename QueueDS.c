#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct QueueStruct {
    int* elements;
    unsigned maximumSize, length, rear, front;
};

typedef struct QueueStruct* Queue;

Queue createQueue (unsigned queueSize) {
    Queue newQueue = (Queue) malloc(sizeof(struct QueueStruct));
    int* vector = (int*) malloc(queueSize * sizeof(int));

    newQueue -> length = newQueue -> rear = newQueue -> front = 0;
    newQueue -> maximumSize = queueSize;
    newQueue -> elements = vector;

    return newQueue;
}

bool isEmpty (Queue queue) { return queue -> length == 0; }

int peekFirstElement (Queue queue) {
    if (!isEmpty(queue)) return queue -> elements[queue -> rear - 1];
}

void enqueue (Queue queue, int element) {
    if (queue -> length == queue -> maximumSize) return;

    unsigned nextStep = (queue -> front + 1 > queue -> maximumSize) ? 0 : queue -> front;

    queue -> elements[nextStep] = element;
    queue -> front = nextStep + 1;
    queue -> length++;
}

void dequeue (Queue queue) {
    if (isEmpty(queue)) return;

    unsigned nextStep = (queue -> rear + 1 > queue -> maximumSize) ? 0 : queue -> rear;

    queue -> rear = nextStep + 1;
    queue -> length--;
}

void printElements (Queue queue) {
    int frontLength = queue -> length - queue -> front,
    frontPart = (frontLength > 0) ? frontLength : queue -> length,
    rearPart = queue -> length - frontPart;

    for (unsigned i = 0; i < frontPart; i++)
        printf("%d ", queue -> elements[queue -> rear + i]);

    for (unsigned i = 0; i < rearPart; i++)
            printf("%d ", queue -> elements[i]);
}

void showQueueInfo (Queue queue) {
    printf("Length: %d\n", queue -> length);
    printf("Maximum Size: %d\n", queue -> maximumSize);
    printElements(queue);
    printf("\n\n");
}

void destroyQueue (Queue queue) {
    free(queue -> elements);
    free(queue);
}

int main (void) {
    Queue myQueue = createQueue(10);

    //Queue initialization
    for (unsigned i = 1; i <= myQueue -> maximumSize; i++)
        enqueue(myQueue, i);

    showQueueInfo(myQueue);

    //Will not work (queue length > max size)
    enqueue(myQueue, 8);

    //Eliminates "1" and "2"
    dequeue(myQueue);
    dequeue(myQueue);

    //Adds "11" and "12" at the queue´s end
    enqueue(myQueue, 11);
    enqueue(myQueue, 12);

    showQueueInfo(myQueue);

    //removing all
    for (unsigned i = 0; i <= myQueue -> maximumSize; i++)
        dequeue(myQueue);

    showQueueInfo(myQueue);

    for (unsigned i = 1; i < myQueue -> maximumSize; i++)
        enqueue(myQueue, i);

    showQueueInfo(myQueue);

    destroyQueue(myQueue);
    return 0;
}
