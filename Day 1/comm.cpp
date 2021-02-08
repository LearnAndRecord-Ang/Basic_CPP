#include<iostream>

using namespace std;

// 组合数解决，从n里面选择k个
int combination(int n, int k)
{
    if (k > n)
    {
        return 0;
    }
    else if (k ==n || k == 0 )
    {
        return 1;
    }
    else
    {
        /* code */
        return combination(n-1,k)+combination(n-1,k-1); //组合数公式 
    }
}

int main()
{
    int n = 18;
    int k = 5;
    cout<<combination(18,5);
}