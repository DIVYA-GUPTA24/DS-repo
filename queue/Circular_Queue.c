#include <stdio.h>
#include <stdlib.h>
#define size 10
#define true 1
#define false 0

struct cqueue
{
    char item[size];
    int front;
    int rear;
};

void initialize(struct cqueue *cq)
{
    cq->front==size-1;
    cq->rear==size-1;
}
int isempty(struct cqueue *cq)
{
    if((cq->rear)==(cq->front))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void enqueue(struct cqueue *cq,char x)
{
    if(((cq->rear+1)%(size))==cq->front)
    {
        printf("queue overflow");
        exit(1);
    }
    cq->rear=(cq->rear+1)%size;
    cq->item[cq->rear]=x;
}
char dequeue(struct cqueue *cq )
{
    if(isempty(cq))
    {
        printf("queue underflow");
        exit(1);
    }

    cq->front=(cq->front+1)%size;
    char x=cq->item[cq->front];
    return x;
}
int main()
{
    struct cqueue mycq;
    char y;
    initialize(&mycq);
    enqueue(&mycq,'A');
    enqueue(&mycq,'B');
    enqueue(&mycq,'C');
    enqueue(&mycq,'D');
    enqueue(&mycq,'E');
    enqueue(&mycq,'F');
    enqueue(&mycq,'G');
    enqueue(&mycq,'H');
    enqueue(&mycq,'I');
    y=dequeue(&mycq);
    printf("%c",y);
    y=dequeue(&mycq);
    printf(" %c",y);
    y=dequeue(&mycq);
    printf(" %c",y);
    y=dequeue(&mycq);
    printf(" %c",y);
    return 0;
}
