#include <iostream>
using namespace std;

class Clock
{
    public:
        Clock(int newHour, int newMinute, int newSecond); // 构造函数
        Clock(); // 默认构造函数

        //若在声明后直接实现，则默认值正常填写，若在类外实现，类外的函数参数表中不需要写默认值
        void setTime(int newHour = 0, int newMinute = 0, int newSecond = 0);
        // {
        //     hour = newHour;
        //     minute = newMinute;
        //     second = newSecond;
        // };
        void showTime();
        // 在类内书写不需要clock::
        // Clock(int h , int m, int s): hour(h), minute(m), second(s){}
        // // Clock::Clock(): hour(0), minute(0), second(0){} 用委托构造函数写法重写
        // Clock():Clock(0,0,0){}
    private:
        int hour,minute,second;
};

//构造函数实现
Clock::Clock(int h , int m, int s): hour(h), minute(m), second(s){}
Clock::Clock():Clock(0,0,0){} // 委托构造函数，等效为Clock::Clock(): hour(0), minute(0), second(0){}

//若在声明后，在类外部实现，则不需要重新写默认值
void Clock::setTime(int newHour, int newMinute, int newSecond)
{
    hour = newHour;
    minute = newMinute;
    second = newSecond;
}

void Clock::showTime()
{
    cout<<hour<<':'<<minute<<':'<<second<<endl;
}

int main()
{
    Clock myClock(10,1,1);
    Clock myClock2; //调用默认构造函数
    myClock2.showTime();
    myClock.setTime(10,2,2);
    myClock.showTime();
    return 0;
}

