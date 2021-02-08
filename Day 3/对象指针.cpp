#include <iostream>
using namespace std;

class Point
{
    public:
        Point(int x = 0, int y = 0);
        int getX()const {return x;};
        int getY()const {return y;};
    private:
        int x,y;
};

Point::Point(int x, int y):x(x),y(y){}


int main()
{
    // int **a[3][4];
    // cout<<sizeof(a);

    Point p1(1,2);
    Point *p2 = &p1;
    cout<<p2->getX()<<endl;
    cout<<(*p2).getX()<<endl;
    cout<<p1.getX()<<endl;
    return 0;
}