
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
		
		析构函数在作用域结束后里面调用
		
        静态和全局的析构函数在最后调用, 调用的顺序跟构造函数的顺序相反
		
		
