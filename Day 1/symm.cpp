#include<iostream>

using namespace std;

// 回文数判断
bool symm(unsigned x)
{
    unsigned origin = x;
    unsigned reverse = 0;
    while (origin > 0)
    {
        reverse = reverse * 10 + origin % 10; //回文数为原来数字对10取余数，然后原来数字每次除以10
        origin /= 10;
    }
    return x == reverse;
}

int main()
{
    int num = 1991;
    cout<<symm(num);
}