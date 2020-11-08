#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
using namespace std;

typedef struct{
    char data;
    double weight;
    int parent, lchild, rchild;
}HTNode;

void InitHFMTree(){
    int n;
    cout << "Please enter the number: " << endl;
    cin >> n;
    char a[n];
    double b[n];
    cout << "Please enter characters: " << endl;
    for(int i = 0 ; i < n ; i++){
        cin >> a[n];
    }
    cout << "Please enter weights: " << endl;
    for(int i = 0 ; i < n ; i++){
        cin >> b[n];
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
    }
    else if (c == 'd' || c == 'D')
    {
    }
    else if (c == 'p' || c == 'P')
    {
    }
    else if (c == 't' || c == 'T')
    {
    }
    else if (c == 'e' || c == 'E')
    {
        return;
    }
    else
    {
        cout << "ERROR" << endl;
        return;
    }
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