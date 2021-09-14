#include <iostream>
#include <string>
using namespace std;

// 1.3 类模板
// 1.3.1 语法
template<class NameType,class AgeType = int>
class Person
{
public:
    NameType m_Name;
    AgeType m_Age;
    Person(NameType name,AgeType age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }
    void show()
    {  
        cout<<"name:"<<this->m_Name<<" age:"<<this->m_Age<<endl;
       
    }
    
};


void test1()
{
   Person<string,int> p1("xcs",18);// 使用类模板并给定参数类型
    p1.show();
}
//  1.3.2 类模板与函数模板区别
// 用上面 定义的 Person类模板
    //1. 类模板没有自动类型推导的使用方式

void test2()
{
 //  Person p("xcs",22); //直接这么写会报错,无法用自动类型推导
    Person<string,int> p1("xcs",18);// 正确，只能是显示指定类型
    p1.show();
}
//2. 类模板在模板参数列表中可以有默认参数
void test3()
{
    
    Person<string> p1("xcs",18);// 因为在定义的时候指定了默认参数
                                //template<class NameType,class AgeType = int>
    p1.show();
}

// 1.3.3 类模板中成员函数创建时机
//  - 普通类中的成员函数是一开始就创建的
//  - 类模板中的成员函数在调用时才创建
class P1
{
public:
    void show1()
    {
       cout<<"show P1"<<endl;
    }
    
};
class P2
{
public:
    void show2()
    {
       cout<<"show P2"<<endl;
    }
    
};

template<class T>
class myClass
{
public:
    T obj;

    // 类模板中的成员函数,并不是一开始创建的，而是在模板调用时再生成
    void f1()
    {
       obj.show1();
    }
    void f2()
    {
       obj.show2();
    }
    
};// 当我不知道obj是啥类型的时候但是 obj.show编译时没错的,也就是说 类模板的成员函数 没有被调用这个 f1,f2 是没有被生成的所以是不会报错的，只有在调用f1，f2的时候才知道obj是个啥
void test4()
{
//    cout<<"test3"<<endl;
    myClass<P1> m;
    m.f1();// 调用f1不会报错,识别obj 为P1
    //m.f2();// 上面已经指定obj为类型P1 而P1 里面是没有show2()函数的 所以是会报错的 但是 你不调用f2 是不会报编译错误的
    // 对比着看 就能知道 类模板的成员函数是什么时候创建的，这里有点绕，实在绕不懂的时候可以先认定结论然后带着结论去对比code理解看
}

// 1.3.4 类模板对象做函数参数
template<class T1,class T2>
class A
{
public:
    T1 m_Name;
    T2 m_Age;
    A(T1 name,T2 age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }
    void show()
    {  
        cout<<"name:"<<this->m_Name<<" age:"<<this->m_Age<<endl;
       
    }
};
    // 1. 指定传入的类型   直接显示对象的数据类型
    // 使用相对广泛
void printA( A<string,int> a)
{
    a.show();
}

void test5()
{
   A<string,int> p("xcs",22);
   printA(p);

}

    
    // 2. 参数模板化  将对象的参数变为模板进行传递
template<class T1,class T2>
void printA2( A<T1,T2> &a)
{
    a.show();
    cout<<"T1 type:"<<typeid(T1).name()<<endl;// 查看这个类型的名字
    cout<<"T2 type:"<<typeid(T2).name()<<endl;
}
void test6()
{
   A<string,int> p("xcs",22);
   printA2(p);
}
    // 3. 整个类模板化  将这个对象类型模板化进行传递
template<class T>
void printA3( T &a)
{
    a.show();
    cout<<"T type:"<<typeid(T).name()<<endl;
}
void test7()
{
    A<string,int> p("xcs",22);
   printA3(p);
}




// 1.3.5 类模板与继承
// 看类模板是如何被继承的？
// 这是一个base类模板
template<class T>
class Base
{
public:
    T m;
    Base()
    {
        cout<<"这是base的构造函数"<<endl;
    }
};

// 定义个普通子类1
// 普通类继承 父类模板类 需指定父类的 模板参数类型
//class son1:public Base // 没有指定 父类的 模板参数的类型 会报错
class son1:public Base<int>
{
public:
    string n;
};
// 定义个普通子类2
// 子类模板继承父类模板
template<class T1,class T2>
class son2:public Base<T1>
{
public:
    T2 n;
    son2()
    {
        cout<<"T1 type:"<<typeid(T1).name()<<endl;
        cout<<"T2 type:"<<typeid(T2).name()<<endl;
    }
};
void test8()
{
   son1 s1; //实例化son1的时候会 调用 父类的 构造函数
   son2<int,string>s2; //  实例化的时候要 显示指定 模板类(包括父类)的参数类型
}

int main()
{
   system("chcp 65001");
   test8();
   system("pause");
   return 0;
}
