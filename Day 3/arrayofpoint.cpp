#include <iostream>
using namespace std;

class Point {
public:
	Point() : x(0), y(0) {
		cout<<"Default Constructor called."<<endl;
	}

	Point(int x, int y) : x(x), y(y) {
		cout<< "Constructor called."<<endl;
	}

	~Point() { cout<<"Destructor called."<<endl; }

	int getX() const { return x; }

	int getY() const { return y; }

	void move(int newX, int newY) {
		x = newX;
		y = newY;
	}
private:
	int x, y;
};

class ArrayOfPoints
{
    public:
        ArrayOfPoints(int size):size(size)
        {
            points = new Point[size];
        }
        ArrayOfPoints();
        ~ArrayOfPoints()
        {
            delete[] points;
        }
        ArrayOfPoints(const ArrayOfPoints& v) ;

        // 返回引用，实现双向传递
        Point &element(int index)
        {
            assert(index >=0 && index <size);
            return points[index];
        }
        // 也可以用指针类型的函数实现
        Point *pointElement(int index)
        {
            assert(index >=0 && index <size);
            return &points[index];
        }

    private:
        Point *points;
        int size;
};

// 深层复制
ArrayOfPoints::ArrayOfPoints(const ArrayOfPoints& v) {
	size = v.size;
    // points = v.points;
	points = new Point[size];
	for (int i = 0; i < size; i++)
    {
        // points[i] = v.points[i]; //points为指针，points[i]为指针的数组表达形式
        *(points+i) = v.points[i]; // 与上一句等效
        cout<<points[i].getX()<<endl; //points是指向对象数组的指针
        cout<<(points+i)->getX()<<endl; //与上一句等效
    }		
}

int main()
{
    int count = 2;
    ArrayOfPoints pointsarr(count);
    pointsarr.element(0).move(5,0);
    pointsarr.pointElement(1)->move(15,20);
    ArrayOfPoints points2(pointsarr);
    return 0;
}
