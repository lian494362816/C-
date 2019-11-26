#include <stdio.h>

// 比较C和C++的写法

// C的写法
struct person1{
    char *name; 
    int age; 
    char *work;

    void (*print_info)(struct person1 *p);
};

void print_info1(struct person1 *p)
{
    printf("name:%s \n", p->name);
    printf("age:%d \n", p->age);
    printf("work:%s \n", p->work);
}

// C++ 写法
class person2 {
    public:
        char *name; 
        int age; 
        char *work;

    // 可以直接访问内部的成员 
    void print_info(void)
    {
        printf("name:%s \n", name);
        printf("age:%d \n", age);
        printf("work:%s \n", work);
    }
};

int main(int argc, char *argv[])
{
    // C 写法
    struct person1 person1_array[2] = {
        {
            .name = "person1_A", 
            .age = 10,
            .work = "AA",
            .print_info = print_info1,
        },

        {
            .name = "person1_B", 
            .age = 20,
            .work = "BB",
            .print_info = print_info1,
        },
    };
    
    printf("C Func==========\n");
    person1_array[0].print_info(&person1_array[0]);
    person1_array[1].print_info(&person1_array[1]);

    // C++ 写法
    struct person2 person2_array[2] = {
        {
            .name = "person2_A", 
            .age = 10,
            .work = "AA",
        },

        {
            .name = "person2_B", 
            .age = 20,
            .work = "BB",
        },
    };

    printf("C++ Func==========\n");
    // 可以直接调用内部的函数
    person2_array[0].print_info();
    person2_array[1].print_info();

    return 0;
}
