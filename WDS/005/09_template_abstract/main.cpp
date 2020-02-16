#include "Human.h"

//测试抽象类界面

#define PRINT 0

#if PRINT
//#include "Chinese.h"
//#include "Englishman.h"
#endif

int main(int argc, char *argv[])
{
    /*
        1 不需要头文件可以创建出Englishman, Chinese, 只不过上行转换成了Human
        2 CreateXXX声明在Human.h 定义在各自类实现中
        3 类实现都编译成库，这样就算类和类的头文件改动了, 也不会影响到main
    */
    Human &e = CreateEnglishman("Jhon", 20, "ShenZheng");
    Human &c = CreateChinese("LCC", 22, "BeiJing");

#if PRINT
    //Chinese *pc = dynamic_cast<Chinese *>(&c);
    //pc->print_info();

    //Englishman *pe = dynamic_cast<Englishman *>(&e);
    //pe->print_info();
#endif

    // Human::~Human使用的是虚函数, 因此会先调用派生类的析构
    delete &e;
    delete &c;

    return 0;
}
