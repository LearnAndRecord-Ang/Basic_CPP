#include <iostream>
using namespace std;

/*
移动构造函数和深层复制构造函数
*/
class IntNum
{
    public:
    //动态构造int类型的指针初始化xptr
        IntNum(int x=0):xptr(new int(x))
        {
            cout<<"constructor"<<endl;
        }
        //深层复制构造函数，构造int对象，初始值为n的xptr指针的对象的值
        IntNum(const IntNum &n):xptr(new int(*n.xptr))
        {
            cout<<"copy constructor"<<endl;
        }
        //移动构造函数
        IntNum(IntNum && n):xptr(n.xptr) //类似浅层复制，直接将参数对象的指针初始化当前指针，
        {
            //注意此处将参数对象的指针置空
            n.xptr = nullptr;
            cout<<"move constructor"<<endl;
        }
        ~IntNum()
        {
            delete xptr;
            cout<<"destructing"<<endl;
        }
        int getInt(){return *xptr;}
    private:
        int *xptr;
};

IntNum getNum()
{
    //a为局部变量，函数结束后，a就消失
    IntNum a;
    //返回a时，若调用了复制构造函数，则会构造一个有新的内存分配的临时的无名对象，然后a自己会被释放
    //返回a时，若调用了移动构造函数，则会将a中的资源转移到临时无名对象，然后a自己会被释放
    return a;
}

int main()
{
    //临时无名对象到主函数中调用getInt()函数
    cout << getNum().getInt() << endl;
    return 0;
}