#include <iostream>
using namespace std;

//指向函数指针
//指针指向程序代码存储区
int compute(int a, int b , int(*func)(int, int))
{
    return func(a,b);
}

int max(int a, int b)
{
    return ((a>b)?a:b);
}

int min(int a, int b)
{
    return ((a<b)?a:b);
}

int main()
{
    int a,b,result;
    a = 5;
    b = 3;

    result = compute(a,b,&max); //可以不写&
    cout<<result;
}