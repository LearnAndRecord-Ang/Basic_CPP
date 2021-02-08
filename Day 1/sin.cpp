#include <iostream>
#include <cmath>
using namespace std;

const double TINY_VALUE = 1e-10;
double sin(double x);

int main()
{
    double k,r,s;
    cout<<"r=";
    cin >> r ;
    cout<<"s = ";
    cin >> s ;
    if (r*r < s*s)
    {
        k = sqrt(sin(r)*sin(r)+ sin(s)+sin(s));
    }
    else
    {
        k = sin(r*s)/2.0;
    }
    cout<<"k="<<k;
    return 0;
}

// sin的泰勒展开
double sin(double x)
{
    double term = x; //项的值，初始值为x
    double index = 1; //第几项
    double result = 0; //sin的值
    do {
        result += term; //sin为各个项的和
        index++; //项数加一
        term = -term * x * x / ( 2 * index - 1 ) / ( 2 * index - 2 ); // 第i项为第i-1项乘以-x*x，并除以[i!/(i-1)!]

    }while (fabs(result) > TINY_VALUE);
    return result;
}