#include<bits/stdc++.h>
using namespace std;

int in, p = 0;
int a, b, c, d, e, f, g, h, i, j;

int main(){
    cin >> in;
    for(a = 1 ; a < 4 ; a++){
        for(b = 1 ; b < 4 ; b++){
            for(c = 1 ; c < 4 ; c++){
                for(d = 1 ; d < 4 ; d++){
                    for(e = 1 ; e < 4 ; e++){
                        for(f = 1 ; f < 4 ; f++){
                            for(g = 1 ; g < 4 ; g++){
                                for(h = 1 ; h < 4 ; h++){
                                    for(i = 1 ; i < 4 ; i++){
                                        for(j = 1 ; j < 4 ; j++){
                                            if(a + b + c + d + e + f + g + h + i + j == in){
                                                p++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(p == 0){
        cout << p;
    }
    else{
        cout << p << endl;
        for(a = 1 ; a < 4 ; a++){
            for(b = 1 ; b < 4 ; b++){
                for(c = 1 ; c < 4 ; c++){
                    for(d = 1 ; d < 4 ; d++){
                        for(e = 1 ; e < 4 ; e++){
                            for(f = 1 ; f < 4 ; f++){
                                for(g = 1 ; g < 4 ; g++){
                                    for(h = 1 ; h < 4 ; h++){
                                        for(i = 1 ; i < 4 ; i++){
                                            for(j = 1 ; j < 4 ; j++){
                                                if(a + b + c + d + e + f + g + h + i + j == in){
                                                    cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << " " << j << endl;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}