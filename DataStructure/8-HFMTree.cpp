#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
using namespace std;

void oprate(char c){
    if(c == 'I' && c == 'i'){
        cout << c << endl;
        return;
    }
    else if(c == 'C' && c == 'c'){
        
    }
    else if(c == 'D' && c == 'd'){
        
    }
    else if(c == 'P' && c == 'p'){
        
    }
    else if(c == 'T' && c == 't'){
        
    }
    else{
        cout << "ERROR" << endl;
    }
    return;
}

int main(){
    char c;
    do{
        cout << "Please choose your operation." << endl;
        cout << "I : Initialization" << endl;
        cout << "C : Encode" << endl;
        cout << "D : Decode" << endl;
        cout << "P : Print codefile" << endl;
        cout << "T : Print Hafman Tree" << endl;
        cout << "E : Exit" << endl;
        c = getchar();
        cout << c;
        //oprate(c);
    }while(c != 'E' || c != 'e');
    return 0;
}