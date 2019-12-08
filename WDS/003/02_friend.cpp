#include <iostream>

//测试友元函数

using namespace std;

class Point {
private:
    int x;
    int y;

public:

    // 空的构造函数
    Point()
    {
        cout << "Point empty constructor" << endl;
    }

    //构造函数
    Point(int x, int y):x(x),y(y)
    {
        cout << "Point constructor" << endl;
    }

    int get_x(void)
    {
        return x;
    }

    int get_y(void)
    {
        return y;
    }

    void set_x(int x)
    {
        this->x = x;
    }

    void set_y(int y)
    {
        this->y = y;
    }

    void print_info(void)
    {
        cout << "x:" << this->x << ",y:" << this->y << endl;
    }

    // 声明一个友元函数
    friend Point add_friend(Point &p1, Point &p2);

    Point add(Point &p1, Point &p2);

    friend void printWidth( void );
};

// 2个对象中x,y 相加
Point Point::add(Point &p1, Point &p2)
{
    Point n;
    // 因为x y 是私有成员，因此只能通过函数来访问
    n.set_x(p1.get_x() + p2.get_x());
    n.set_y(p1.get_y() + p2.get_y());

    return n;
}


// 友元函数的实现
Point add_friend(Point &p1, Point &p2)
{
    Point n;
    // 因为是友元函数，因此可以直接访问私有成员
    n.x = p1.x + p2.x;
    n.y = p1.y + p2.y;
    return n;
}

int main(int argc, char *argv[])
{
    Point p1(10, 20);
    Point p2(20, 30);

    Point p3 = p3.add(p1, p2);

    // 友元函数需要直接调用
    // p4.add_friend(p1, p2) 这种调用方式是错误的
    Point p4 = add_friend(p1, p2);

    p3.print_info();
    p4.print_info();

    return 0;
}
