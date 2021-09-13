#pragma onces
#include <iostream>
#include <string>
using namespace std;
// // 定义的模板类
// template<class T1,class T2>
// class Xcs
// {
// public:
//     T1 m_name;
//     T2 m_age;
//     Xcs(T1,T2);
//     void show();
// };


//普通的Person 类
class Person
{
public:
    string m_Name;
    int m_Age;
    Person(string name,int age);
    void show();
    
};

