#include <iostream>
using namespace std;

class Complex
{
    public:
        Complex(double r= 0,double i = 0):real(r),imag(i){}
        //运算符重载为非成员函数，如实数+复数，且实数在加号左边
        friend Complex operator -(const Complex &c1, const Complex &c2);
        friend Complex operator +(const Complex &c1, const Complex &c2);
        //类库里的，没有权利修改，只能重载为类外的非成员函数
        friend ostream & operator << (ostream &out,const Complex &c);
    private:
        double real,imag;
};

Complex operator +(const Complex &c1, const Complex &c2)
{
    //构造临时无名对象返回
    return Complex(c1.real+c2.real,c1.imag+c2.imag);
}
Complex operator -(const Complex &c1, const Complex &c2)
{
    return Complex(c1.real-c2.real,c1.imag-c2.imag);
}
ostream & operator << (ostream &out,const Complex &c)
{
    out<<"("<<c.real<<", "<<c.imag<<")";
    return out;
}

int main()
{
    Complex c1(5,4),c2(2,10),c3;
    c3 = c1-c2;
    cout<<c3<<endl;
    return 0;
}