#include <iostream>

//将重载操作放到类的内部

//#define USE_FRIEND

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

#if USE_FRIEND
    friend Point operator+(Point &p1, Point &p2);
    friend Point &operator++(Point &p);
    friend Point operator++(Point &p, int not_use);
#else
    // 在内部实现运算符重载
    // 第一个参数必须是类本身，否则只能用友元实现


    //对比外部的实现，Point operator+(Point &p1, Point &p2)
    Point operator+(Point &p)
    {
        Point n;
        n.x = p.y + this->x;
        n.y = p.y + this->y;
        return n;
    }

    //对比外部的实现Point &operator++(Point &p)
    // ++p
    Point &operator++()
    {
        this->x += 1;
        this->y += 1;
        return *this;
    }

    //对比外部的实现Point operator++(Point &p, int not_use)
    // p++
    Point operator++(int not_use)
    {
        Point n;
        n = *this;
        this->x += 1;
        this->y += 1;
        return n;
    }
#endif

    // 因为第1个参数是ostream， 所有只能用友元来实现
    friend ostream &operator<<(ostream &o, Point p);
};

#if USE_FRIEND
Point operator+(Point &p1, Point &p2)
{
    Point n;
    n.x = p1.x + p2.x;
    n.y = p1.y + p2.y;
    return n;
}

// ++p
Point &operator++(Point &p)
{
    p.x += 1;
    p.y += 1;
    return p;
}

// p++
Point operator++(Point &p, int not_use)
{
    Point n;
    n = p;

    p.x += 1;
    p.y += 1;

    return n;
}
#endif

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

    cout << "p++" << endl;
    Point p2 = p1++;
    cout << p1;
    cout << p2;

    cout << "++p" << endl;
    Point p3 = ++p1;
    cout << p1;
    cout << p3;


    return 0;
}
