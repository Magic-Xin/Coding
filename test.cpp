#include<stdio.h>

int main()
{
long y=-43456;
printf("y=%-8ld\n", y);
printf("y=%-08ld\n", y);
printf("y=%08ld\n", y);
printf("y=%+8ld\n", y);
}