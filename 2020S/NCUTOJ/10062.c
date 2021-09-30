#include<stdio.h>
#include<string.h>

char lower(char temp){
    if(temp >= 'A' && temp <= 'Z'){
        temp = temp - 'A' + 'a';
    }
    return temp;
}

int main(){
    char a[80], b[80];
    int i;
    fgets(a, 80, stdin);
    fgets(b, 80, stdin);
    for(i = 0 ; i < strlen(a) ; i++){
        a[i] = lower(a[i]);
    }
    for(i = 0 ; i < strlen(b) ; i++){
        b[i] = lower(b[i]);
    }
    if(strcmp(a, b) > 0){
        printf(">");
    }
    else if(strcmp(a, b) < 0){
        printf("<");
    }
    else{
        printf("=");
    }
    return 0;
}
