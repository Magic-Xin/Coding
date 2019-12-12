#include <stdio.h>

int main()
{
     int i,j,n;
     int a[100];
     scanf("%d",&n);
     for(i=0;i<n;i++){
         a[i]=i+1;
     }
     for(i=1;i<n;i++){
         if(a[i]==0){
            continue;
         }
         for(j=i+1;j<n;j++){
              if(a[j]%a[i]==0){
                   a[j]=0;
              }
         }
     }
     for(j=1;j<n;j++){
         if(a[j]!=0){
              printf("%d ",a[j]);
         }
     }
     printf("\n");
     return 0;
}