#include <iostream>
using namespace std;

class Base1
{
    public:
        Base1(int i){ cout <<"Base1 created! "<<i<<endl;}
};

class Base2
{
    public:
        Base2(int i){ cout <<"Base2 created! "<<i<<endl;}
};

class Base3
{
    public:
        Base3(){ cout <<"Base3 created! "<<endl;}
};

class Derived : public Base2,public Base1,public Base3 // 注意基类名顺序
{
    
    public:
        Derived(int a, int b , int c, int d):Base1(a),member2(d),member1(c),Base2(b){} //注意成员对象名的个数和顺序
    private:
        Base1 member1;
        Base2 member2;
        Base3 member3;
};

int main()
{
    Derived obj(1,2,3,4); 
    return 0;
}