#include <stdio.h> 

int main(){
    double in, out;
    scanf("%lf", &in);
     if(in <= 100000){
         out = in * 0.1;
     }
     else if(in <=200000){
         out = (in - 100000) * 0.075 + 10000;
     }
     else if(in <= 400000){
         out = (in - 200000) * 0.05 + 17500;
     }
     else if(in <= 600000){
         out = (in - 400000) * 0.03 + 27500;
     }
     else if(in <= 1000000){
         out = (in - 600000) * 0.015 + 33500;
     }
     else{
         out = (in - 1000000) * 0.01 + 39500;
     }
    printf("%.2lf", out);
    return 0;
}
