//我的代码比较结构化，容易理解
//在此也建议大家多用用string类，c++有关于string的特大好处，c和pascal都没有哦
//
//定义头文件
#include <iostream>
#include <string>
//命名空间
using namespace std;
int main(){
    //定义两个字符串
    string a;
    string b;
    //用string库，调用getline, 直接读入一整行
    getline(cin,a);
    getline(cin,b);
    //转换大小写，可以都转换为大写，或者小写
    for (int i=0;i<a.length();++i){
        a[i]=tolower(a[i]);
    }
    for (int i=0;i<b.length();++i){
        b[i]=tolower(b[i]);
    }
    //因为连起来的不算，所以要在前后加几个空格，一定要是同样多的，同量减同量，等于同量
    a= ' ' + a + ' ';
    b= ' ' + b + ' ';
    //先看看会不会找不到，用a.find()和string::npos
    if (b.find(a) == string::npos){
        cout << -1 << endl;
    }
    //如果找得到
    else {
        int alpha = b.find(a);
        int beta = b.find(a), s = 0;//计数器初始化为0
        while (beta != string::npos){
            ++s;//计数器
            beta = b.find(a,beta+1);
        }
        cout << s << " " << alpha << endl;//输出第一个和总共有几个
    }
    //函数返回值为0，结束整个程序
    return 0;
}