#include <iostream>
#include <stdio.h>

// 测试强制类型转换

using namespace std;

int main(void)
{
    // 1 将char * 转化为 int *
    char *str1 = "hello";
    // 等价于 int *p1 = (int *)str1
    int *p1 = reinterpret_cast<int *>(str1);

    // 这里暂且使用c的printf打印，因为很便捷
    printf("str1:%p, p1:%p \n", str1, p1);
    printf("str1:%s, p1:%s \n", str1, p1);


    // 2 去掉const修饰符
    const char *str2 = "const hello";
    char *p2 = const_cast<char *>(str2);

    printf("str2:%p, p2:%p \n", str2, p2);
    printf("str2:%s, p2:%s \n", str2, p2);

    return 0;
}

