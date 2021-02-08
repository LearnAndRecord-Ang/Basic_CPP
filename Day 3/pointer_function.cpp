#include<iostream>
using namespace std;

//指针类型的函数

//PART 1
// int* fun()
// {
//     static int local = 1;
//     return &local;
// }

// int main()
// {
//     int *ptr = fun();
//     cout<<*ptr;
//     return 0;
// }

//PART 2
// int *search(int *a, int n)
// {
//     for (int i = 0;i<n;i++)
//     {
//         // cout<<*(a+i);
//         if (*(a+i) == 0)
//         {
//             // cout<<*(a+i);
//             return a+i;
//         }
//     }
//     return a;
// }

// int main()
// {
//     int arr[10] = {9,1,1,343,2,2,32,1,0,5};
//     // for (int i = 0;i<10;i++)
//     // {
//     //     cin>>arr[i];
//     // }
//     int *zeroptr = search(arr,10);
//     cout<<*zeroptr;
//     return 0;
// }

//PART 3

int* newintvar()
{
    int* ptr = new int();
    return ptr;
} //函数结束，ptr中地址依然有效

int main()
{
    // int* newintvar(); 若函数体在前，则可省略，函数体在后，则要先声明
    int *intptr = newintvar();
    *intptr = 5;
    cout<<*intptr;
    delete intptr; //内存释放
    return 0;
}

