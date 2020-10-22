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

Status InitBTree(BTree &BT)
{
    BT = NULL;
    return OK;
}

Status CreatBTree(BTree &BT)
{
    char temp;
    cin >> temp;
    if (temp == '\n')
    {
        return OK;
    }
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
        CreatBTree(BT->lchild);
        CreatBTree(BT->rchild);
    }
}

int main()
{
    BTree BT;
    InitBTree(BT);
    char a[15] = {'A', 'B', 'C', '#', '#', 'D', 'E', '#', 'G', '#', '#', 'F', '#', '#', '#'};
    CreatBTree(BT);
    return 0;
}