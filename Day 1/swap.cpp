#include <iostream>
using namespace std;

//swap two numbers
//void swap(int a, int b) 错误写法，a，b只存在与函数内部，无法传出。
void swap(int &a, int &b) //引用传递，此时a是x的别名,因此保持了和主函数的联系
{
    int t = a;
    cout<< &a<<endl;
    a = b;
    b = t;
}

int main()
{
    int x = 5, y = 10;
    cout<< &x<<endl;
    cout<<"x = "<<x<<"; y = "<<y<<endl;
    swap(x,y);
    cout<<"x = "<<x<<"; y = "<<y;
    return 0;
}