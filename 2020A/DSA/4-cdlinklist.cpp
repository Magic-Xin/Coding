#include <bits/stdc++.h>
#define Status int
#define ElemType char
#define ERROR 0
#define OK 1
using namespace std;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

typedef struct CLNode
{
    ElemType data;
    struct CLNode *next, *end;
} CLNode, *CLinkList;

Status CreateList(LinkList &L, int n, char a[])
{
    L = (LinkList)malloc(sizeof(LNode));
    if (!L)
    {
        return ERROR;
    }
    L->next = NULL;
    for (int i = 0; i < n; i++)
    {
        LinkList p;
        p = (LinkList)malloc(sizeof(LNode));
        p->data = a[i];
        p->next = L->next;
        L->next = p;
    }
    return OK;
}

Status InitCLinkList(CLinkList &L)
{
    L = (CLinkList)malloc(sizeof(CLNode));
    if (!L)
    {
        return ERROR;
    }
    L->end = L->next = L;
    return OK;
}

Status InsertCLinkList(CLinkList &L, char a){
    CLinkList p;
    p = (CLinkList)malloc(sizeof(CLNode));
    if(!p){
        return ERROR;
    }
    p->data = a;
    p->next = L;
    L->end->next = p;
    L->end = p;
    return OK;
}

Status Solution(LinkList L, CLinkList &INT_L, CLinkList &CHAR_L, CLinkList &OTHER_L)
{
    if (!L)
    {
        return ERROR;
    }
    LinkList p;
    p = L->next;
    while (p)
    {
        if (p->data >= '0' && p->data <= '9')
        {
            InsertCLinkList(INT_L, p->data);
        }
        else if (p->data >= 'a' && p->data <= 'z')
        {
            InsertCLinkList(CHAR_L, p->data);
        }
        else
        {
            InsertCLinkList(OTHER_L, p->data);
        }
        p = p->next;
    }
    return OK;
}

Status PrintCLinkList(CLinkList L){
    if(!L){
        return  ERROR;
    }
    CLinkList p;
    p = L->next;
    while(p != L){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    return OK;
}

int main()
{
    LinkList L;
    CLinkList INT_L, CHAR_L, OTHER_L;
    char a[10] = {'1', '2', 'c', 'd', '5', '?', '%', 'h', 'i', '0'};
    CreateList(L, 10, a);
    InitCLinkList(INT_L);
    InitCLinkList(CHAR_L);
    InitCLinkList(OTHER_L);
    Solution(L, INT_L, CHAR_L, OTHER_L);
    PrintCLinkList(INT_L);
    PrintCLinkList(CHAR_L);
    PrintCLinkList(OTHER_L);
    return 0;
}