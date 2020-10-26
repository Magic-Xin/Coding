#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define Status int
#define ERROR 0
#define OK 1
#define STACK_INIT_SIZE 200
#define STACKINCREMENT 20
using namespace std;

struct Car
{
    int num;
    int time;
};

typedef struct
{
    Car *base;
    Car *top;
    int stacksize;
    int length;
} SqStack;

typedef struct QNode
{
    Car QCar;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

Status InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front)
    {
        return ERROR;
    }
    Q.front->next = NULL;
    return OK;
}

Status EnQueue(LinkQueue &Q, Car c)
{
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
    {
        return ERROR;
    }
    p->QCar.num = c.num;
    p->QCar.time = c.time;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

Status DeQueue(LinkQueue &Q, Car &c)
{
    if (Q.front == Q.rear)
    {
        return ERROR;
    }
    QueuePtr p;
    p = Q.front->next;
    c.num = p->QCar.num;
    c.time = p->QCar.time;
    Q.front->next = p->next;
    if (Q.rear == p)
    {
        Q.rear = Q.front;
    }
    free(p);
    return OK;
}

Status InitStack(SqStack &S)
{
    S.base = (Car *)malloc(STACK_INIT_SIZE * sizeof(Car));
    if (!S.base)
    {
        return ERROR;
    }
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    S.length = 0;
    return OK;
}

Status Push(SqStack &S, Car e)
{
    if (S.top - S.base >= S.stacksize)
    {
        S.base = (Car *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(Car));
        if (!S.base)
        {
            return ERROR;
        }
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    S.length++;
    return OK;
}

Status Pop(SqStack &S, Car &e)
{
    if (S.top == S.base)
    {
        return ERROR;
    }
    e = *--S.top;
    S.length--;
    return OK;
}

Status Locate(LinkQueue Q, int e)
{
    QueuePtr p;
    p = Q.front->next;
    while (p)
    {
        if (p->QCar.num == e)
        {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

int main()
{
    Car temp;
    SqStack S, So;
    LinkQueue Q;
    InitStack(S);
    InitStack(So);
    InitQueue(Q);
    int max;
    double price;
    cin >> max >> price;
    int s, num, time;
    while (cin >> s >> num >> time)
    {
        if (s == 0 && num == 0 && time == 0)
        {
            break;
        }
        temp.num = num;
        temp.time = time;
        if (s == 0)
        {
            if (S.length < max)
            {
                Push(S, temp);
            }
            else
            {
                EnQueue(Q, temp);
            }
        }
        else
        {
            if (!Locate(Q, num))
            {
                Pop(S, temp);
                while (temp.num != num)
                {
                    Push(So, temp);
                    Pop(S, temp);
                }
                double sum = (time - temp.time) * price;
                printf("%d %.2lf\n", num, sum);
                while (So.top != So.base)
                {
                    Pop(So, temp);
                    Push(S, temp);
                }
                while (S.length < max)
                {
                    if (Q.front != Q.rear)
                    {
                        DeQueue(Q, temp);
                        Push(S, temp);
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                DeQueue(Q, temp);
                while (temp.num != num)
                {
                    EnQueue(Q, temp);
                    DeQueue(Q, temp);
                }
            }
        }
    }
    while (S.length)
    {
        Pop(S, temp);
        Push(So, temp);
    }
    while (So.length)
    {
        Pop(So, temp);
        cout << temp.num << " ";
    }
    cout << endl;
    while (Q.front != Q.rear)
    {
        DeQueue(Q, temp);
        cout << temp.num << " ";
    }
    cout << endl;
    return 0;
}