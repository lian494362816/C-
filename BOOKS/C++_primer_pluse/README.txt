
01_Chapter
    2.1.cpp  
        测试 cout
    2.2.cpp 
        测试 整型变量
    2.3.cpp
        测试 cin
    2.4.cpp
        测试函数sqrt
    2.5.cpp
        测试函数的定义 

03_Chapter
    3.1.cpp 
        测试short,int,long,long long的长度及最大值
    3.2.cpp
        cout 打印8进制， 16进制
    3.3.cpp
        使用cout.put() 来打印字符

04_Chapter
    01_array_sizeof.cpp
        测试数组的使用，测试sizeof的使用
    02_string.cpp
        测试字符串，通过strlen来打印字符串长度
        通过cin来输入字符串，cin会把空格当做结束标志，因此输入带空格的字符串
        如“New York" 

    03_get_getline.cpp
        测试cin.get()和cin.getline
        推荐使用cin.get(x,x).get 

    04_get_int_string.cpp
        通过(cin >> xx).get() 来获取整数

    05_string_class.cpp
        测试string 类的功能

    06_union.cpp
        联合体和匿名联合体

    07_pointer.cpp
        打印指针的值和地址

    08_new.cpp
        new 的基本使用

    09_new_array.cpp
        使用new 来创建数组

    010_get_name.cpp
        使用new delete 来获取串口输入的字符串

05_Chapter
    01_new_for.cpp
        使用c++11 新特性的for语句

        注：编译时需要添加-std=c++11; 
            g++ 01_new_for.cpp  -std=c++11

    02_txtin.cpp
        获取串口的输入，统计最终接受到的字符个数(不包括空格)
        
    03_txtin.cpp
        使用cin.get()获取串口的输入，统计最终接受到的字符个数(包括空格)

06_Chapter
    01_fstream.cpp
        从串口读取数据写入文件，再从文件读取写入的内容打印

07_Chapter
    01_string_array.cpp
        传递string 数组
