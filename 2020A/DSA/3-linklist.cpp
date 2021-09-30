#include <bits/stdc++.h>
#define ElemType int
#define Status int
#define OK 1
#define ERROR 0
using namespace std;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

class Solution
{
public:
    Status CreateList(LinkList &L, int n, int a[])
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

    Status SimpleMergeList(LinkList &La, LinkList &Lb){
        LinkList ha, hb;
        ha = La->next;
        hb = Lb->next;
        while(ha->next != NULL){
            ha = ha->next;
        }
        ha->next = hb;
        return OK;
    }

    Status PrintList (LinkList L){
        LinkList pt;
        pt = L->next;
        while(pt){
            cout << pt->data << " ";
            pt = pt->next;
        }
        cout << endl;
        return OK;
    }

    Status DeleteInterval(LinkList &L, int m, int n){
        LinkList pm, pn, temp, temp2;
        pm = pn = NULL;
        temp = L->next;
        while(temp->next != NULL){
            if((temp->next)->data > m && pm == NULL){
                pm = temp;
            }
            if(temp->data >= n && pn == NULL){
                pn = temp;
            }
            temp = temp->next;
        }
        temp = pm->next;
        while(temp != pn){
            temp2 = temp->next;
            free(temp);
            temp = temp2;
        }
        pm->next = pn;
        return OK;
    }
};

int main()
{
    Solution solution;
    LinkList L1, L2;
    int a[5] = {5, 4, 3, 2, 1};
    int b[4] = {9, 8, 7, 6};
    solution.CreateList(L1, 5, a);
    solution.CreateList(L2, 4, b);
    solution.SimpleMergeList(L1, L2);
    solution.PrintList(L1);
    solution.DeleteInterval(L1, 3, 6);
    solution.PrintList(L1);
    return 0;
}
