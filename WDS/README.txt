
001
    001_struct_class.cpp  
        比较C和C++的对变量，函数封装的写法

    002_this.cpp
        C++使用this指针，给成员名和变量名相同的情况下赋值

    003_out.cpp
        将函数写到类的外面

    004_div    
        把类的实现拆分成多个文件

    005_namespace_implement
        引入namespace, 在定义类的时候使用

    006_using
        using 只能指定命名空间里面的一个东西

    007_namespace
        使用了namespace来指定空间

    008_cout_endl
        引入了sd:: 中的cout 和 endl

002 
	01_overload.cpp  
		测试函数重载
	
    02_ref.cpp
		测试引入
		
	03_constructor.cpp
		构造函数的使用，new的简单使用
	
	04_deconstructor.cpp
		析构函数的使用
		使用new申请的类， 需要手动调用delete才会触发析构函数
	
	05_cp_constructor.cpp
		默认拷贝构造函数

		如果不提供拷贝构造函数，系统会调用默认的拷贝构造函数
		默认的拷贝构造函数，使用相同的地址
		当调用析构时，2次析构函数释放的是相同的指针
		导致指针被释放2次，因此需要自己实现拷贝构造函数

	06_class_order.cpp
		构造函数的调用顺序
		构造函数的调用顺序跟在代码中的顺序一致
		
		全局对象的构函数在main之前调用，且只调用1次
		静态对象的构造函数只调用1次
		局部对象的构造函数可调用多次
		
		析构函数在作用域结束后调用
		
        静态和全局的析构函数在最后调用, 调用的顺序跟构造函数的顺序相反
		
	07_other_class.cpp
		测试对象中有其它类
		
		会先调用对象中其它类的构造函数
		再调用自己的构造函数
		析构函数的调用顺序与构造函数的调用顺序相反

		可以通过:来调用其它类的构造函数
		
003
	01_static_member.cpp
		测试静态成员
		
	02_friend.cpp
		测试友元函数
		友元函数可以直接访问私有成员
		友元函数可以需要直接调用
		
	03_opt_overload.cpp
		测试重载运算符，在类的外部实现
		
	04_cout_overload.cpp
		重载cout
		
	05_opt_overload_in.cpp
		测试运算重载，在类的内部实现

	06_opt_equal_in.cpp
		测试重载等于操作符和拷贝构造函数的调用区别
		在创建对象并使用=赋值时, 调用拷贝构造函数
        在创建完对象之后使用=赋值时, 调用重载运算符=
		
	07_const.cpp
		拷贝构造函数必须使用const修饰，否则使用const 修饰的对象去赋值给另一个对象时会报错
		因为const 对象只能调用const修饰的成员函数

004
    01_public_inherit.cpp
        公有继承

    02_public_inherit.cpp
        测试类的public继承，私有成员，保护成员，公有成员的访问权限

    03_public_inherit.cpp
        测试类的public继承，使用using class::number 修改基类成员的属性
    
    04_inherit.cpp
        测试类的publibc,protected,private继承的属性

        继承属性总结：
        1. 3种继承,pri 属性依旧保持不变
        2. pub继承，所有属性不变
        3. pro继承，pub属性变为pro
        4. pri继承，所有属性变为pri

        访问属性:
        1. 3种继承，在成员内部访问情况是一样的，可以访问pub和pro,不能访问pri
        2. pub继承，对象只能访问基类的pub成员
        3. pro继承，对象不能访问基类的任何成员
        4. pri继承，对象不能访问基类的任何成员

    05_mul_inherit.cpp
        测试类的多重继承属性

    06_override.cpp
        重写

    07_inherit_space.cpp
        测试派生类的空间分布
