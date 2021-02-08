#include <iostream>
using namespace std;

class Base1
{
    public:
        virtual void display() const; //虚函数，虚函数类外实现，不能内类实现
        // virtual void display() const = 0; //纯虚函数，则不能定义base1对象
};

void Base1::display()const
{
    cout<<"Base1"<<endl;
}

class Base2:public Base1
{
    public:
        virtual void display() const; //虚函数，提示编译器在编译阶段不要作任何操作
};

void Base2::display()const
{
    cout<<"Base2"<<endl;
}

class Derived:public Base2
{
    public:
        virtual void display() const;
};

void Derived::display()const
{
    cout<<"D"<<endl;
}

// 参数为指向基类对象对指针
void fun(Base1* ptr) //若base1含有纯虚函数，可以定义base1的指针
{
    ptr->display();
}

int main()
{
    Base1 base1; //若是base1有纯虚函数则不能定义对象
    Base2 base2;
    Derived d;
    fun(&base1);
    fun(&base2);
    fun(&d);
    return 0;
}