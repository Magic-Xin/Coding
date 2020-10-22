#include <bits/stdc++.h>
#define Status int
#define ElemType char
#define ERROR 0
#define OK 1
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
using namespace std;

typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
} Sqlist;

class Solution
{
public:
    Status InitList_Sq(Sqlist &L)
    {
        L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
        if (!L.elem)
        {
            exit(OVERFLOW);
        }
        L.length = 0;
        L.listsize = LIST_INIT_SIZE;
        return OK;
    }

    Status CopyData_Sq(Sqlist &L, char a[], int a_len)
    {
        if (a_len > L.listsize)
        {
            return ERROR;
        }
        for (int i = 0; i < a_len; i++)
        {
            L.elem[i] = a[i];
            L.length++;
        }
        return OK;
    }

    Status PrintData_Sq(Sqlist L)
    {
        for (int i = 0; i < L.length; i++)
        {
            cout << L.elem[i];
        }
        cout << endl;
        return OK;
    }

    Status ListInsert_Sq(Sqlist &L, int i, ElemType e)
    {
        if (i < 0 || i > L.length)
        {
            return ERROR;
        }
        if (L.length >= L.listsize)
        {
            ElemType *newbase;
            newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
            if (!newbase)
            {
                exit(OVERFLOW);
            }
            L.elem = newbase;
            L.listsize += LISTINCREMENT;
        }
        ElemType *q = &(L.elem[i]);
        for (ElemType *p = &(L.elem[L.length]); p >= q; p--)
        {
            *(p + 1) = *p;
        }
        *q = e;
        L.length++;
        return OK;
    }

    Status UpsetData_Sq(Sqlist &L, int m, int n)
    {
        if (m >= n)
        {
            return OK;
        }
        ElemType temp;
        temp = L.elem[m];
        L.elem[m] = L.elem[n];
        L.elem[n] = temp;
        UpsetData_Sq(L, m + 1, n - 1);
        return OK;
    }
};

int main()
{
    Solution solution;
    Sqlist L;
    char a[6] = {'a', 'b', 'c', 'd', 'f', 'g'};
    solution.InitList_Sq(L);
    solution.CopyData_Sq(L, a, sizeof(a));
    solution.PrintData_Sq(L);
    solution.ListInsert_Sq(L, 0, 'z');
    solution.PrintData_Sq(L);
    solution.UpsetData_Sq(L, 0, L.length - 1);
    solution.PrintData_Sq(L);
    return 0;
}