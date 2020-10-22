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
        cout << BT->data << endl;
        PrintBTree(BT->lchild);
        PrintBTree(BT->rchild);
    }
    return OK;
}

Status CheckBTree(BTree BT, int target, TElemType &e){
    if(target < 1){
        return ERROR;
    }
    if(BT != NULL){
        e = BT->data;
        step++;
        if(step >= target){
            return OK;
        }
        CheckBTree(BT->lchild, target, e);
        CheckBTree(BT->rchild, target, e);
    }
    return OK;
}

Status NumBTree(BTree BT, int &num){
    if(BT != NULL){
        num++;
        NumBTree(BT->lchild, num);
        NumBTree(BT->rchild, num);
    }
    return OK;
}

BTree InvertBTree(BTree &BT){
    if(BT == NULL){
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
    char a[15] = {'A', 'B', 'C', '#', '#', 'D', 'E', '#', 'G', '#', '#', 'F', '#', '#', '#'};
    CreatBTree(BT, a, sizeof(a));

    TElemType e;
    step = 0;
    CheckBTree(BT, 4, e);
    cout << e << endl;

    int num = 0;
    NumBTree(BT, num);
    cout << num << endl;

    BT = InvertBTree(BT);
    PrintBTree(BT);
    return 0;
}