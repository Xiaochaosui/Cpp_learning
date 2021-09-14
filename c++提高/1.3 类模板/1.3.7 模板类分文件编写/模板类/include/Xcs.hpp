#pragma onces
#include <iostream>
#include <string>
using namespace std;
// // 定义的模板类
template<class T1,class T2>
class Xcs
{
public:
    T1 m_name;
    T2 m_age;
    Xcs(T1,T2);
    void show();
};
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



