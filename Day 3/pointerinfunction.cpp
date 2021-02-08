#include <iostream>
using namespace std;

// 指针作为函数参数
void splitFloat(float x, int *intPart ,float *fracPart)
{
    *intPart = static_cast<int>(x);
    *fracPart = x-*intPart;
}

int main()
{
    float f,x = 169.9;
    int n;
    splitFloat(x,&n,&f);
    cout<<n<<" "<<f;
}