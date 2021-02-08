#include <iostream>
using namespace std;

int i = 1; //全局变量，静态生存期

void other()
{
    // a,b 为静态局部变量，具有全局寿命，局部可见
    // 只有第一次进入函数时被初始化
    static int a = 2;
    static int b; //默认为0
    // c为局部变量，动态生命周期
    int c = 10;
    a += 2;
    i += 32;
    c += 5;
    cout<<"--OTHER--\n";
    cout<<" i: "<<i<<" a: "<<a<<" b: "<<b<<" c: "<<c<<endl;
    b = a;
}

int main()
{
    //a,b,c和other里面的不同，只是名字相同
    static int a; //静态局部变量，默认为0
    int b = -10;
    int c = 0;
    
    cout<<"----main----\n";
    cout<<" i: "<<i<<" a: "<<a<<" b: "<<b<<" c: "<<c<<endl;
    c += 8;
    other();

    cout<<"----main----\n";
    cout<<" i: "<<i<<" a: "<<a<<" b: "<<b<<" c: "<<c<<endl;
    i += 10;
    other();
    return 0;
}