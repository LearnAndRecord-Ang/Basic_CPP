#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    private: 
        int x,y;
    public:
        Point(int x, int y);
        Point();
        Point(const Point &p);
        int getX();
        int getY();
};

Point::Point(int p_x, int p_y):x(p_x),y(p_y){}
Point::Point():Point(0,0){}

int Point::getX()
{
    return x;
}
int Point::getY()
{
    return y;
}

Point::Point(const Point &p)
{
    x = p.x;
    y = p.y;
    cout<< "calling the copy constructor of point"<<endl;
}

class Line
{
    private:
        Point p1,p2; //根据定义顺序初始化
        double length;
    public:
        Line(Point name1, Point name2);
        Line(const Line &line_len);
        double getLength()
        {
            return length;
        }
};

//组合类构造函数
Line::Line(Point name1, Point name2):p1(name1),p2(name2) //初始化顺序为private里面的顺序
{
    cout<<"call constructor of line"<<endl;
    double x = static_cast<double>(p1.getX()-p2.getX());
    double y = static_cast<double>(p1.getY()-p2.getY());
    length = sqrt(x*x + y*y);
}

Line::Line(const Line &line):p1(line.p1),p2(line.p2)
{
     cout<<"Calling the copy construtor of Line"<<endl;
     length = line.length;
}

int main()
{
    Point p1(1,1),p2(4,5);
    Line line(p1,p2); //复制顺序为从右到左 调用4次point复制构造函数，分别是实参和形参结合2次，line构造函数初始化列表2次
    Line line2(line);
    cout<<"length1 = "<< line.getLength()<<endl;
    cout<<"length2 = "<< line2.getLength()<<endl;
}

