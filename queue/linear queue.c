#include <stdio.h>
#include <stdlib.h>
#define size 10
#define true 1
#define false 0

struct queue
{
    char item[10];
    int front;
    int rear;
};

void initialize(struct queue *q)
{
    q->front=0;
    q->rear=-1;
}

int isempty(struct queue *q)
{
    if(((q->rear)+(q->front)+1)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(struct queue *q,char x)
{
    if(q->rear==(size-1))
    {
        printf("queue overflow");
        exit(1);
    }
    q->rear++;
    q->item[q->rear]=x;
}

char dequeue(struct queue *q )
{
    if(isempty(q))
    {
        printf("queue underflow");
        exit(1);
    }
    char x=q->item[q->front];
    q->front++;
    return x;
}
int main()
{
    struct queue myq;
    char y;
    initialize(&myq);
    enqueue(&myq,'A');
    enqueue(&myq,'B');
    enqueue(&myq,'C');
    enqueue(&myq,'D');
    y=dequeue(&myq);
    printf("%c",y);
    y=dequeue(&myq);
    printf(" %c",y);
    y=dequeue(&myq);
    printf(" %c",y);
    y=dequeue(&myq);
    printf(" %c",y);
    y=dequeue(&myq);
    printf(" %c",y);
    return 0;
}
