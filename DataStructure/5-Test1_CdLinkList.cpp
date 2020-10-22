#include <iostream>
#include <stdlib.h>
#define Status int
#define ElemType int
#define ERROR 0
#define OK 1
using namespace std;

typedef struct CLNode
{
    ElemType data, num;
    struct CLNode *prior, *next;
} CLNode, *CLinkList;

Status CreatCLinkList(CLinkList &L, int a[], int n)
{
    L = (CLinkList)malloc(sizeof(CLNode));
    if (!L)
    {
        return ERROR;
    }
    L->prior = L->next = L;
    CLinkList p, q;
    p = L;
    for (int i = 0; i < n; i++)
    {
        if(i == 0){
            p->data = a[i];
            p->num = i+1;
            continue;
        }
        q = (CLinkList)malloc(sizeof(CLNode));
        q->data = a[i];
        q->num = i+1;
        q->prior = p;
        p->next = q;
        p = q;
    }
    p->next = L;
    L->prior = q;
    return OK;
}

Status Sort_Joseph(CLinkList &L, int m, int n)
{
    if(!L){
        return ERROR;
    }
    CLinkList p, q;
    p = L;
    for(int i = 0 ; i < n ; i++){
        while(--m){
            p = p->next;
        }
        cout << p->num << " ";
        m = p->data;
        p->next->prior = p->prior;
        p->prior->next = p->next;
        q = p;
        p = p->next;
        free(q);
    }
    return OK;
}

int main()
{
    CLinkList L;
    int m, n;
    cin >> m >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    CreatCLinkList(L, a, n);
    Sort_Joseph(L, m, n);
    return 0;
}