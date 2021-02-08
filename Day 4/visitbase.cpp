#include <iostream>
using namespace std;

class Base1
{
    public:
    int var;
    void fun()
    {
        cout << "Base1 : var" << var << endl;
    }
};

class Base2
{
    public:
    int var;
    void fun()
    {
        cout << "Base2: var" << var <<endl;
    }
};

class Derived : public Base1, public Base2
{
    public:
        int var;
        void fun()
        {
            cout << "Derived: var" << var <<endl;
        }
};

int main()
{
    Derived d;
    Derived *p = &d;

    d.var = 1;
    //同名隐藏，只调用了derived类中的fun()函数
    d.fun();
    
    //类名限定
    d.Base1::var = 2;
    d.Base1::fun();

    p ->Base2::var = 3;
    p ->Base2::fun();
}