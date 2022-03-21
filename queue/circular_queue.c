

#include <stdio.h>
#include <stdlib.h>

typedef struct queue_t  {

    int size;
    int front;
    int rear;
    int *data;
} queue;

void
queue_init (queue **q, int size) {

    queue *temp = (queue *)malloc (sizeof (struct queue_t));
    temp->front = 0;
    temp->rear = 0;
    temp->size = size;
    temp->data = (int *)malloc (size * sizeof (int));
    *q = temp;

}

void 
enqueue (queue **q, int element) {

    printf ("Enqueuing %d \n", element);
    /* check for queue full */
    queue *q1 = *q;
    if ((q1->rear + 1) % q1->size == q1->front) {
         printf ("Queue is full \n");
    } else {
        q1->rear = (q1->rear + 1) %  q1->size;
        q1->data [q1->rear] = element;
    }
}

int 
dequeue (queue **q) {

    /* check for queue empty */
    queue *q1 = *q;
    if (q1->rear  == q1->front) {
         printf ("Queue is empty \n");
         return -1;
    } else {
        q1->front = (q1->front + 1) %  q1->size;
        return q1->data [q1->front];
    }
}

int main () {


    queue *q;

    printf ("Queue implementing circular \n");

    queue_init (&q, 5);
    
    enqueue (&q , 1);
    enqueue (&q , 2);
    enqueue (&q , 3);
    enqueue (&q , 4);
    enqueue (&q , 5);
    enqueue (&q , 6);


    printf ("Deq element %d \n",  dequeue (&q));

    enqueue (&q , 6);

    printf ("Deq element %d \n",  dequeue (&q));
    printf ("Deq element %d \n",  dequeue (&q));
    printf ("Deq element %d \n",  dequeue (&q));
    printf ("Deq element %d \n",  dequeue (&q));
    printf ("Deq element %d \n",  dequeue (&q));

}