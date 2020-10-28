#include <iostream>
#include <stdlib.h>
#define TElemType char
#define Status int
#define OK 1
#define ERROR 0
using namespace std;

typedef struct BTNode
{
    TElemType data;
    struct BTNode *lchild, *rchild;
} BTNode, *BTree;

int step = 0;

Status InitBTree(BTree &BT)
{
    BT = NULL;
    return OK;
}

Status CreatBTree(BTree &BT, TElemType a[], int n)
{
    if (step >= n)
    {
        return OK;
    }
    char temp = a[step];
    step++;
    if (temp == '#')
    {
        BT = NULL;
    }
    else
    {
        BT = (BTree)malloc(sizeof(BTNode));
        if (!BT)
        {
            return ERROR;
        }
        BT->data = temp;
        CreatBTree(BT->lchild, a, n);
        CreatBTree(BT->rchild, a, n);
    }
    return OK;
}

Status PrintBTree(BTree BT)
{
    if (BT != NULL)
    {
        cout << BT->data << " ";
        PrintBTree(BT->lchild);
        PrintBTree(BT->rchild);
    }
    return OK;
}

Status CheckBTree(BTree BT, int num)
{
    if (BT != NULL)
    {
        step++;
        if(step == num){
            cout << BT->data << endl;
        }
        CheckBTree(BT->lchild, num);
        CheckBTree(BT->rchild, num);
    }
    return OK;
}

Status CountBTree(BTree BT, int &num)
{
    if (BT != NULL)
    {
        if (BT->lchild == NULL && BT->rchild == NULL)
        {
            num++;
        }
        CountBTree(BT->lchild, num);
        CountBTree(BT->rchild, num);
    }
    return OK;
}

BTree InvertBTree(BTree &BT)
{
    if (BT == NULL)
    {
        return NULL;
    }
    BTNode *temp = BT->rchild;
    BT->rchild = InvertBTree(BT->lchild);
    BT->lchild = InvertBTree(temp);
    return BT;
}

int main()
{
    BTree BT;
    InitBTree(BT);
    char a[21] = {'A', 'B', 'D', 'H', '#', '#', 'I', '#', '#', 'E', '#', '#', 'C', 'F', '#', 'J', '#', '#', 'G', '#', '#'};
    CreatBTree(BT, a, sizeof(a));
    PrintBTree(BT);
    cout << endl;

    step = 0;
    CheckBTree(BT, 4);

    int num = 0;
    CountBTree(BT, num);
    cout << num << endl;

    BT = InvertBTree(BT);
    PrintBTree(BT);
    return 0;
}