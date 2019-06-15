#include <iostream>
#include <string>

using namespace std;

struct student{
    int type;
    union id{
        int num;
        char grade;
    }id_val;
};

struct anonymous_student {
    int type;
    union {
        int num;
        char grade;
    };
};

void print_stu(struct student *p)
{
    if (1 == p->type)
    {
        cout << "num:" << p->id_val.num << endl;
    }

    if (2 == p->type)
    {
        cout << "grade:" << p->id_val.grade << endl;
    }
}


void print_stu2(struct anonymous_student *p)
{
    if (1 == p->type)
    {
        cout << "num:" << p->num << endl;
    }

    if (2 == p->type)
    {
        cout << "grade:" << p->grade << endl;
    }
}

int main(void)
{
    struct student stu1 = {
        .type = 1,
        .id_val = {
            .num = 10,
        },
    };

    struct student stu2 = {
        .type = 2,
        .id_val = {
            .grade = 'A',
        },
    };

    print_stu(&stu1);
    print_stu(&stu2);

    struct anonymous_student stu3 = {1, 30,};
    struct anonymous_student stu4 = {2, 'B',};

    print_stu2(&stu3);
    print_stu2(&stu4);

    return 0;
}
