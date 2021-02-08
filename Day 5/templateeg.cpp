#include <iostream>
using std::cout;
using std::endl;

template <typename T> //函数模板定义
void outputArray(const T *array, int count){
    for ( int i = 0 ; i < count ; i++ ){
        cout << array[i] <<" ";
    }
    cout << endl;
}

int main(){
    const int aCount = 8, bCount = 8, cCount = 20;
    int a[aCount] = {1, 2, 3, 4, 5, 6, 7, 8};
    double b[bCount] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};
    char c[cCount] = "Hello world!";

    cout << "a array contains:" <<endl;
    outputArray(a,aCount);
    cout << "b array contains:" <<endl;
    outputArray(b,bCount);
    cout << "c array contains:" <<endl;
    outputArray(c,cCount);
    return 0;
}