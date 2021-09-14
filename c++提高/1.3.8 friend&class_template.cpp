#include <iostream>
#include <cmath>
#include <string>
using namespace std;
// 1.3.8 类模板与友元
//类模板配合友元函数的类内和类类外实现
// 通过全局函数打印Person 的信息

// 提前让编译器知道Person类的存在
template<class T1,class T2>
class Person;
// 类外实现 全局函数，不需要加 class的作用域
template<class T1,class T2>
void printPer2(Person<T1,T2> p)
{   
    cout<<"类外实现"<<endl;   
    cout<<"name:"<<p.m_Name<<" age:"<<p.m_Age<<endl;
}

template<class T1,class T2>
class Person
{

    // 全局函数 类内实现 ,为什么说这是全局函数，也就是说这里传进来的参数p 不是自身 而是其他的一个实例化对象，并且访问这个p的 私有属性m_Name，m_Age 故使用友元的技术
    friend void printPer(Person<T1,T2> p)
    {    cout<<"类内实现"<<endl;  
         cout<<"name:"<<p.m_Name<<" age:"<<p.m_Age<<endl;
    }
    // 全局函数 类外实现
    // 加空模板的参数列表 <>
    // 如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
    friend void printPer2<>(Person<T1,T2> p);

public:

    Person(T1 name,T2 age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }
  

private:
    T1 m_Name;
    T2 m_Age;
};



//全局函数 类内实现  测试
void test1()
{
   Person<string,int> p("xcs",22);
   printPer(p);
}
//全局函数 类外实现  测试
void test2()
{
   Person<string,int> p("xcsy",22);
   printPer2(p);
}
int main()
{
   system("chcp 65001");
   test1();
   test2();
   system("pause");
   return 0;
}
