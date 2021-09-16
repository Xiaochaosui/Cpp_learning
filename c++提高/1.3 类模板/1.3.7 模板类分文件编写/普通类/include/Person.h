#pragma onces
#include <iostream>
#include <string>
using namespace std;

//普通的Person 类
// 普通类分文件编写
class Person
{
public:
    string m_Name;
    int m_Age;
    Person(string name,int age);
    void show();
    
};


