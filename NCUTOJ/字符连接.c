#include<stdio.h>
#include<string.h>

int main(){
	char a[80] = {'\0'}, b[80] = {'\0'};
	gets(a);
	gets(b);
	int i;
	for(i = 0 ; i < strlen(a) ; ++i){
			printf("%c", a[i]);
	}
	if(strlen(b) < 5){
		for(i = 0 ; i < strlen(b) ; ++i){
			printf("%c", b[i]);
		}
	}
	else{
		for(i = 0 ; i < 5 ; ++i){
			printf("%c", b[i]);
		}
	}
	return 0;
}

