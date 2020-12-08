#include <bits/stdc++.h>
#define Status int
#define ElemType char
#define ERROR 0
#define OK 1
using namespace std;

typedef struct DuLNode
{
    ElemType data;
    int freq;
    struct DuLNode *prior, *next;
} DuLNode, *DuLinkList;

Status InitDuLinkList(DuLinkList &L, char a[], int n){
    L = (DuLinkList)malloc (sizeof(DuLNode));
    if(!L){
        return ERROR;
    }
    L->prior = L->next = L;
    DuLinkList p, q;
    p = L;
    for(int i = 0 ; i < n ; i++){
        q = (DuLinkList)malloc(sizeof(DuLNode));
        q->data = a[i];
        q->freq = 0;
        q->prior = p;
        p->next = q;
        p = q;
    }
    p->next = L;
    L->prior = q;
    return OK;
}

Status Locate(DuLinkList &L, ElemType e){
    DuLinkList p, q;
    p = L->next;
    while(p != L){
        if(p->data == e){
            break;
        }
        p = p->next;
    }
    p->freq++;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    q = p;
    while(q != L){
        q = q->prior;
        if(q->freq >= p->freq){
            break;
        }
    }
    p->next = q->next;
    p->prior = q;
    q->next->prior = p;
    q->next = p;
    return OK;
}

Status PrintDuLinkList(DuLinkList L){
    if(!L){
        return ERROR;
    }
    DuLinkList p;
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
    DuLinkList L;
    char a[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    InitDuLinkList(L, a, 10);
    Locate(L, 'd');
    Locate(L, 'e');
    Locate(L, 'f');
    Locate(L, 'a');
    Locate(L, 'e');
    Locate(L, 'a');
    Locate(L, 'd');
    Locate(L, 'd');
    PrintDuLinkList(L);
    return 0;
}