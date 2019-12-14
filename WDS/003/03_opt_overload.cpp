#include <iostream>

//测试重载运算符

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

    // 申明为友元函数, 这里可以直接访问私有成员
    friend Point operator+(Point &p1, Point &p2);
    // 前缀++
    friend Point &operator++(Point &p);
    // 后缀++
    friend Point operator++(Point &p, int not_use);
};

// 重载运算操作符'+'
// 前面需要使用关键字operator
Point operator+(Point &p1, Point &p2)
{
    Point n;
    n.x = p1.x + p2.x;
    n.y = p1.y + p2.y;

    return n;
}

//重载运算符 p++, 前缀++
// 这里返回引用可以加快代码的执行速度
// 如过不返回引用的话，代码会调用构造和析构函数，增加了执行步骤
Point &operator++(Point &p)
{
    p.x += 1;
    p.y += 1;

    return p;
}

//重载运算符 ++p, 后缀++
Point operator++(Point &p, int not_use)
{
    Point n;
    n = p;
    p.x += 1;
    p.y += 1;
    return n;
}

int main(int argc, char *argv[])
{
    Point p1(10, 20);
    Point p2(20, 30);

    Point p3 = p1 + p2;

    // p3.x = 30, p3.y =50;
    p3.print_info();
    cout << "==============" << endl;
    // 后缀++，p3,p4的值不同
    Point p4 = p3++;
    //Point p4 = operator++(p3,0); //与上面的等价
    p4.print_info();
    p3.print_info();
    cout << "==============" << endl;

    // 前缀++，p3,p5的值相同
    Point p5 = ++p3;
    //Point p5 = operator++(p3); //与上面的等价
    p5.print_info();
    p3.print_info();
    cout << "==============" << endl;

    return 0;
}
