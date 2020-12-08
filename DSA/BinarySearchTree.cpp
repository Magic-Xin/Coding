#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct BSTNode
{
    int data;
    BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

void createBSTree(BSTree &BST, int a)
{
    BSTNode *p;
    p = BST;
    if (p == NULL)
    {
        BST = (BSTree)malloc(sizeof(BSTNode));
        BST->data = a;
        BST->lchild = BST->rchild = NULL;
    }
    else
    {
        BSTNode *q;
        while (p != NULL)
        {
            q = p;
            if (p->data > a)
            {
                p = p->lchild;
            }
            else
            {
                p = p->rchild;
            }
        }
        p = (BSTree)malloc(sizeof(BSTNode));
        p->data = a;
        p->lchild = p->rchild = NULL;
        if (q->data > a)
        {
            q->lchild = p;
        }
        else
        {
            q->rchild = p;
        }
    }
    return;
}

void PrintBSTree(BSTree BST)
{
    if (BST == NULL)
    {
        return;
    }
    PrintBSTree(BST->lchild);
    cout << BST->data << " ";
    PrintBSTree(BST->rchild);
    return;
}

void Solute(BSTree BST, int a, int &k)
{
    if (BST == NULL)
    {
        return;
    }
    Solute(BST->lchild, a, k);
    if (BST->data != a)
    {
        cout << BST->data << " ";
        k++;
    }
    a = BST->data;
    Solute(BST->rchild, a, k);
    return;
}

int main()
{
    BSTree BST = NULL;
    int a;
    while ((cin >> a) && a != -1)
    {
        createBSTree(BST, a);
    }
    int k = 0;
    PrintBSTree(BST);
    cout << endl;
    Solute(BST, -1, k);
    cout << endl;
    cout << k << endl;
    return 0;
}