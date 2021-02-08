#include <iostream>
#include <list>
#include <deque>
using namespace std;

template <class T>
void printContainer(const char* msg, const T& s)
{
    cout<< msg <<":";
    copy(s.begin(),s.end(),ostream_iteraor<int>(cout, " "));
    cout<<endl;
}

int main()
{
    deque<int> s;
    for(int i = 0;i<10;i++)
    {
        int x;
        cin >> x;
        s.push_front(x);
    }
    printContainer("de",s);
    list<int> l(s.rbegin(),s.rend());
    printContainer("list",l);

    // 相邻两个元素位置互换
    list<int>::iterator itr = l.begin();
    while (itr != l.end())
    {
        /* code */
        int v = *itr;
        itr = l.erase(itr);
        l.insert(++itr,v);
    }
    printContainer("list2",l);

    s.assign(l.begin(),l.end());
    printContainer("de2",s);

    return 0;
}