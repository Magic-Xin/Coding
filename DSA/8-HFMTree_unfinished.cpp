#include <iostream>
#include <cstdlib>
#include <cstdio>
#define OK 1
#define ERROR 0
using namespace std;

typedef struct BTreeNode
{
    int weight;
    char data;
    struct BTreeNode *lchild, *rchild;
} BTreeNode, *BTree;

BTree HBTree;
int n;

BTree CreateHuffman(int a[], char c[])
{
    int i, j;
    struct BTreeNode **b, *q;
    b = (BTree *)malloc(n * sizeof(BTreeNode));
    for (i = 0; i < n; i++)
    {
        b[i] = (BTree)malloc(sizeof(BTreeNode));
        b[i]->data = c[i];
        b[i]->weight = a[i];
        b[i]->lchild = b[i]->rchild = NULL;
    }
    for (i = 1; i < n; i++)
    {
        int k1 = -1, k2;
        for (j = 0; j < n; j++)
        {
            if (b[j] != NULL && k1 == -1)
            {
                k1 = j;
                continue;
            }
            if (b[j] != NULL)
            {
                k2 = j;
                break;
            }
        }
        for (j = k2; j < n; j++)
        {
            if (b[j] != NULL)
            {
                if (b[j]->weight < b[k1]->weight)
                {
                    k2 = k1;
                    k1 = j;
                }
                else if (b[j]->weight < b[k2]->weight)
                    k2 = j;
            }
        }
        q = (BTree)malloc(sizeof(BTreeNode));
        q->weight = b[k1]->weight + b[k2]->weight;
        q->data = '*';
        q->lchild = b[k1];
        q->rchild = b[k2];

        b[k1] = q;
        b[k2] = NULL;
    }
    free(b);
    return q;
}

void PrintTree(BTree BT)
{
    if (BT == NULL)
    {
        cout << "# ";
        return;
    }
    cout << BT->data << " ";
    PrintTree(BT->lchild);
    PrintTree(BT->rchild);
    return;
}

void InitHFMTree()
{
    cout << "Please enter the num: " << endl;
    cin >> n;
    if (n <= 1)
    {
        cout << "Wrong num!" << endl;
        return;
    }
    int a[n];
    char c[n];
    cout << "Please enter char and weights: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i] >> a[i];
    }
    HBTree = CreateHuffman(a, c);
    cout << "Create Complete!" << endl;
    return;
}

void HuffManCoding(BTree BT, int len)
{
    if(BT == NULL){
        cout << "No Tree!" << endl;
        return;
    }
    int a[10];
    
    if (BT != NULL)
    {
        if (BT->lchild == NULL && BT->rchild == NULL)
        {
            int i;
            cout << BT->data << ": ";
            for (i = 0; i < len; i++)
            {
                cout << a[i];
            }
            cout << endl;
        }
        else
        {
            a[len] = 0;
            HuffManCoding(BT->lchild, len + 1);
            a[len] = 1;
            HuffManCoding(BT->rchild, len + 1);
        }
    }
}

void PrintMenu()
{
    cout << "Please choose your operation." << endl;
    cout << "I : Initialization" << endl;
    cout << "C : Encode" << endl;
    cout << "D : Decode" << endl;
    cout << "P : Print codefile" << endl;
    cout << "T : Print Hafman Tree" << endl;
    cout << "E : Exit" << endl;
    return;
}

void Operate(char c)
{
    if (c == 'i' || c == 'I')
    {
        InitHFMTree();
    }
    else if (c == 'c' || c == 'C')
    {
        HuffManCoding(HBTree, 0);
    }
    else if (c == 'd' || c == 'D')
    {
    }
    else if (c == 'p' || c == 'P')
    {
    }
    else if (c == 't' || c == 'T')
    {
        PrintTree(HBTree);
        cout << endl;
    }
    else if (c == 'e' || c == 'E')
    {
        return;
    }
    else
    {
        cout << "ERROR" << endl;
    }
    return;
}

int main()
{
    char c;
    do
    {
        PrintMenu();
        cin >> c;
        Operate(c);
    } while (c != 'e' && c != 'E');
    return 0;
}