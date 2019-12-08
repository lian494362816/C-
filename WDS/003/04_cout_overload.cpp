#include <iostream>

//重载cout

using namespace std;

class Point {
private:
    int x;
    int y;

public:

    // 空的构造函数
    Point()
    {
        //cout << "Point empty constructor" << endl;
    }

    //构造函数
    Point(int x, int y):x(x),y(y)
    {
        //cout << "Point constructor" << endl;
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

    friend ostream &operator<<(ostream &o, Point p);
};

// 重载运算符cout
ostream &operator<<(ostream &o, Point p)
{
    cout << "x:" << p.x << ",y:" << p.y << endl;
    return o;
}

int main(int argc, char *argv[])
{
    Point p1(10, 20);

    cout << p1;

    // 下面的调用与上面的等价
    operator<<(cout, p1);


    return 0;
}
