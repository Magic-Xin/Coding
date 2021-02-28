#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Node
{
    int data, num;
    struct Node *prior, *next;
} Node, *LL;

void CL(LL &L){
    L = (LL)malloc(sizeof(Node));
    L->prior = L->next = L;
    LL p, q;
    p = L;
    for(int i = 0 ; i < 666 ; i++){
        if(i == 0){
            p->num = i+1;
            p->data = 1;
            continue;
        }
        q = (LL)malloc(sizeof(Node));
        q->data = 1;
        q->num = i+1;
        q->prior = p;
        p->next = q;
        p = q;
    }
    p->next = L;
    L->prior = q;
    return;
}

int count(LL &L){
    if(!L) return 0;
    int t = 0;
    LL p;
    p = L->next;
    while(p != L){
        if(p->data){
            t++;
        }
        p = p->next;
    }
    return t;
}

void sort(LL &L){
    LL p, q;
    p = L;
    int t = 1;
    while(count(L) != 1){
        if(p->data){
            if(t % 2 == 1){
                p->data = 0;
                p = p->next;
            } else {
                p = p->next;
            }
            t++;
        } else {
            p = p->next;
        }
    }
    p = L;
    while(!p->data) p = p->next;
    cout << p->num << endl;
    return;
}


int main(){
    LL L;
    CL(L);
    sort(L);
    return 0;
}