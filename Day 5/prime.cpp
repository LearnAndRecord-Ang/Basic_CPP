#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// 判断一个数字是不是质数，判断能否被比它小的质数整除即可
int main()
{
    int n = 50, count = 0;
    std::vector<int> arr(5);

    // 检查i能否被比它小的质数整除
    for (int i = 2; i <= n; i++ )
    {
        bool isPrime = true;
        for (int j = 0 ; j < count ; j++)
        {
            if (i%arr[j] == 0)
            {
                isPrime =false;
                break;
            }
        }
        if (isPrime)
        {
            // cout<<arr.capacity(); 获取容量大小
            arr[count++] = i;
        }
    }
    for (int i = 0;i<count;i++)
    {
        cout<<setw(8)<<arr[i];
    }
    cout<<endl;
    return 0;
}