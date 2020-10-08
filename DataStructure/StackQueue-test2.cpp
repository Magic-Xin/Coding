#include <bits/stdc++.h>
#define Status int
#define ElemType int
#define ERROR 0
#define OK 1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
using namespace std;

typedef struct
{
    ElemType *base;
    ElemType *top;
    int stacksize;
    int length;
} SqStack;

typedef struct QNode{
    ElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q){
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if(!Q.front){
        return ERROR;
    }
    Q.front->next = NULL;
    return OK;
}

Status EnQueue(LinkQueue &Q, ElemType e){
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if(!p){
        return ERROR;
    }
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

Status DeQueue(LinkQueue &Q, ElemType e){
    if(Q.front == Q.rear){
        return ERROR;
    }
    QueuePtr p;
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if(Q.rear == p){
        Q.rear = Q.front;
    }
    free(p);
    return OK;
}

Status InitStack(SqStack &S)
{
    S.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!S.base)
    {
        return ERROR;
    }
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    S.length = 0;
    return OK;
}

Status Push(SqStack &S, ElemType e)
{
    if (S.top - S.base >= S.stacksize)
    {
        S.base = (ElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT)*sizeof(ElemType));
        if(!S.base){
            return ERROR;
        }
        S.top = S.base+S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    S.length++;
    return OK;
}

Status Pop(SqStack &S, ElemType &e){
    if(S.top == S.base){
        return ERROR;
    }
    e = *--S.top;
    return OK;
}

int main()
{
    SqStack S, St;
    LinkQueue Q;
    InitStack(S);
    InitStack(St);
    InitQueue(Q);
    return 0;
}