#include <iostream>
#include <iomanip>

using namespace std;
// enum GameResult
// {
//     WIN,
//     LOSE,
//     TIE,
//     CANCEL
// };

// int main()
// {
//     // cout<<"hello world";
//     // return 0;
//     // float a = 3.1415;
//     // float b = 3.5555;
//     // cout<<setprecision(3)<<a<<setw(8)<<b;
//     // return 0;
//     GameResult result; //声明枚举
//     enum GameResult omit = CANCEL; //可以带着enum声明并赋值
//     GameResult omit2 = CANCEL; //可以不带enum
//     for (int i = 0; i < CANCEL; i++) //枚举数值可以赋值给int型
//     {
//         /* code */
//         result = GameResult(i); //int型需要经过枚举转化才能赋值
//         cout<<i;
//         if (result == WIN)
//         {
//             cout<<"100";
//         }
//     }
//     return 0;

// }

double arctan(double x);

int main()
{
    double a = 16.0*arctan(1/5.0);
    double b = 4.0*arctan(1/239.0);
    cout<< "PI="<<a-b;
    return 0;
}

// 计算pi
double arctan(double x)
{
    double sqr = x*x;
    double e = x;
    double result = 0;
    int i = 1;
    while (e/i > 1e-15)
    {
        double term = e / i;
        if (i % 4 == 1 )
        {
            result = result + term;
        }
        else
        {
            result = result - term;
        }
        e = e*sqr;
        i+=2;
    }
    return result;
}