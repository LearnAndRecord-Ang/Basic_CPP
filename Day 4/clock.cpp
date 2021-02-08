#include <iostream>
using namespace std;

class Clock
{
    public:
        Clock(int hour = 0, int minute = 0,int second = 0);
        void showTime()const;
        // 前置++运算
        Clock &operator ++();
        // 后置++运算
        Clock operator ++(int);
    private:
        int hour,minute,second;
};

Clock::Clock(int hour,int minute,int second)
{
    if (0<=hour&&hour<24 && 0<=minute&&minute<60 && 0 <= second&&second< 60)
    {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }
    else
    {
        /* code */
        cout<<"error"<<endl;
    }
}

void Clock::showTime() const
{
    cout<<hour<<" : "<<minute<<" : "<<second<<endl;
}

// 返回值为本类对象的引用，返回为左值，先增1，后引用，可以直接对返回对象进行操作
Clock &Clock::operator ++()
{
    second++;
    if (second >=60)
    {
        second -= 60; minute++;
        if (minute >= 60)
        {
            minute -=60;
            hour=(hour+1)%24;
        }
    }
    return *this;
}

// 返回为还没有进行+1时候所复制的一个副本，是一个右值，不可以对对象进行操作
Clock Clock::operator ++(int)
{
    Clock old = *this;
    ++(*this); //调用前置“++”运算符
    return old;
}

int main()
{
    Clock myClock(23,59,59);
    myClock.showTime();
    (myClock++).showTime();
    (++myClock).showTime();
}