#include <iostream>
using namespace std;

class Complex
{
    public:
        Complex(double real = 0.0, double i = 0.0):real(real),i(i){}
        //运算符重载为成员函数，如复数加复数
        Complex operator +(const Complex &c2)const;
        Complex operator -(const Complex &c2)const;
        void display()const;
    private:
        double real,i;
};
// 运算符重载
Complex Complex::operator +(const Complex &c2) const
{
    return Complex(real+c2.real,i+c2.i);
}
// 运算符重载
Complex Complex::operator -(const Complex &c2) const
{
    return Complex(real-c2.real,i-c2.i);
}

void Complex::display()const
{
    cout<<real<<" "<<i<<endl;
}

int main()
{
    Complex c1(1,2),c2(2,10),c3;
    c3 = c1+c2;
    c3.display();
}