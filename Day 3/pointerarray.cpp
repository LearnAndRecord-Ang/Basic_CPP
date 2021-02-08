#include <iostream>
using namespace std;

int main()
{
    int line1[] = {1,0,0};
    int line2[] = {0,1,0};
    int line3[] = {0,0,1};
    int b[2][2] = {1,2,3,4};
    //定义整型指针数组并初始化，line1,2,3 相互之间地址不一定是连续的
    int *pLine[3] = {line1,line2,line3};
    // int (*p)[3] = &line1;
    int (*p)[2] = b;

    for (int i = 0; i<3 ; i++)
    {
        for (int j = 0 ; j < 3 ; j++)
        {
            cout<<pLine[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<b<<endl;
    cout<<&b<<endl;
    cout<<line1<<endl;
    cout<<*p<<endl;
    cout<<*(*(p+1))<<endl;
    cout<<*(*p+1)<<endl;
    cout<<*((*p)+1)<<endl;
    // cout<<*p+1<<endl;
    // cout<<b[1][0]<<endl;
    return 0;
}