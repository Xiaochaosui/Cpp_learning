#include <iostream>
#include <string>
#include "Person.h" // 这句表示和头文件产生关联
using namespace std;
// 普通类的成员函数实现
Person::Person(string name,int age)
{
    this->m_Age = age;
    this->m_Name = name;
}

void Person::show()
{  
    cout<<"name:"<<this->m_Name<<" age:"<<this->m_Age<<endl;
    
}
