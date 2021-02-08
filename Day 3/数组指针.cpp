#include <iostream>
using namespace std;

int main()
{
    int (*cp)[8][9] = new int[7][8][9]; // 指向数组的指针，\创建三维数组，需要数个指向[8][9]二维数组的指针来接受首地址
    for (int i = 0 ; i < 7 ; i++)
    {
        for (int j = 0 ; j < 9 ; j++)
        {
            for ( int k = 0; k <8 ; k++)
            {
                *(*(*(cp+i)+j)+k) = (i*100+j*10+k);
                // cp[i][j][k]和*(*(*(cp+i)+j)+k)作用一致
            }
        }
    }

    for (int i = 0 ; i < 7 ; i++)
    {
        for (int j = 0 ; j < 9 ; j++)
        {
            for ( int k = 0; k <8 ; k++)
            {
                cout<< cp[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    delete[] cp;
    return 0;
}
