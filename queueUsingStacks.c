#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct stack{
    int top;
    int capacity;
    int* arr;
};

void constructStack(struct stack* s,int capacity){
    s->capacity=capacity;
    s->arr=(int*)malloc(capacity * sizeof(int));
    s->top=-1;
}

bool empty(struct stack *s){
    return (s->top==-1);
}

bool full(struct stack* s){
    return (s->top==s->capacity-1);
}

void push(struct stack* s,int x){
    if(full(s)){
        return;
    }
    s->arr[++s->top]=x;
}

int pop(struct stack* s){
    if(empty(s)){
        return '\0';
    }
    return s->arr[s->top--];
}

int top(struct stack* s){
    if(empty(s)){
        return -1;
    }
    return s->arr[s->top];
}

struct queue{
    struct stack s1;
    struct stack s2; 
    int capacity;
};

void constructQueue(struct queue *q, int capacity){
    constructStack(&q->s1,capacity);
    constructStack(&q->s2,capacity);
    q->capacity=capacity;
}

bool queueEmpty(struct queue *q){
    return empty(&q->s1) && empty(&q->s2);
}

bool queueFull(struct queue *q){
    return q->s1.top+q->s2.top==q->capacity-2;
}

void queuePush(struct queue *q, int x){
    if(queueFull(q)){
        return;
    }
    push(&q->s1,x);
}

int queuePop(struct queue *q){
    if(queueEmpty(q)){
        return -1;
    }
    if(empty(&q->s2)){
        while(!empty(&q->s1)){
            push(&q->s2,pop(&q->s1));
        }
    }
    return pop(&q->s2);
}

int queueTop(struct queue *q){
    if(queueEmpty(q)){
        return -1;
    }
    if(empty(&q->s2)){
        while(!empty(&q->s1)){
            push(&q->s2,pop(&q->s1));
        }
    }
    return top(&q->s2);
}


int main(){
    struct queue q;
    printf("Enter capacity of queue: ");
    int n;
    scanf("%d",&n);
    constructQueue(&q,n);
    printf("%d\n",queueEmpty(&q));
    printf("%d\n",queueFull(&q));
    queuePush(&q,10);
    queuePush(&q,20);
    printf("%d\n",queueEmpty(&q));
    printf("%d\n",queueFull(&q));
    queuePush(&q,30);
    queuePush(&q,40);
    printf("%d\n",queueEmpty(&q));
    printf("%d\n",queueFull(&q));
    printf("%d\n",queuePop(&q));
    printf("%d\n",queuePop(&q));
}