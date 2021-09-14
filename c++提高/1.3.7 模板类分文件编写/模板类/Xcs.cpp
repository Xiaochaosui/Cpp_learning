#include <iostream>
#include <string>
#include "Xcs.h"
using namespace std;
// 第一种方式 就是把类的定义都写到一个.cpp 文件下 不需要头文件预处理

// Xcs 类外实现 Xcs()构造函数
template<class T1,class T2>
Xcs<T1,T2>::Xcs(T1 name,T2 age)
{
    this->m_age = age;
    this->m_name = name;
}
template<class T1,class T2>
void Xcs<T1,T2>::show()// 加上模板参数
{  
        cout<<"name:"<<this->m_name<<" age:"<<this->m_age<<endl;
       
}

