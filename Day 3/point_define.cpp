#include<iostream>
using namespace std;

int main()
{
    int i;
    int *ptr = &i; //取i的地址赋给ptr
    // int *ptr;
    // ptr = &i;
    i = 10;
    cout<<"i = "<<i<<endl;
    cout<<"*ptr = "<<*ptr<<endl; //输出int型指针所指地址的内容

    // void voidObject; 错误，不可以声明void类型变量
    void *p2; //正确，可以声明void类型指针，该指针可以被赋予任何类型对象的地址，p2本身类型确定是指针，但是所指向的对象不确定
    int j = 5;
    p2 = &j; //void类型指针指向整型变量
    int *p3 = static_cast<int*>(p2); //void 指针转换为int指针
    cout<<"*p3 = "<<*p3;
    return 0;
}
