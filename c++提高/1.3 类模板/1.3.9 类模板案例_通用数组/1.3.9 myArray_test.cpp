#include <iostream>
#include <cmath>
#include <string>
#include "myArray.hpp"
using namespace std;


// 实现一个通用的数组类(类似于STL中的Vector)

// 在MyArry中存入的是int类型(内置类型)的测试
void test1()
{
   MyArray<int> arr1(5);
    for (int i = 0; i < 5; i++)
    {
        //利用尾插法向数组中插入数据
        arr1.push_back(i);
    }
    cout<<"arr1 的打印输出:"<<arr1<<endl; // 重载左移运算符<<   打印输出 MyArry
    cout<<"arr1[0] 的打印输出:"<<arr1[0]<<endl;
    cout<<"arr1 大小:"<<arr1.getSize()<<endl;
    cout<<"arr1 容量:"<<arr1.getCapacity()<<endl;
    MyArray<int> arr2(arr1);
    cout<<"arr2 的打印输出:"<<arr2<<endl;
    arr2.pop_back();
    cout<<"arr2执行pop_back()"<<endl;
    cout<<"arr2 容量:"<<arr2.getCapacity()<<endl;
    cout<<"arr2 大小:"<<arr2.getSize()<<endl;
   
//     MyArry<int> arr3(100);
//    arr3 = arr1;
}

// 自定义数据类型测试
class Person
{
public:
    string m_Name;
    int m_Age;
    Person(){}; // Pay Attention！！！  这个无参构造必须写，因为在下面声明MyArry<Person> arr(10);的时候，没有无参构造会报申请内存空间的错误
    Person(string name,int age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }

};

void printPersonArray(MyArray<Person> &arr)
{
   for (int i = 0; i < arr.getSize(); i++)
   {
       cout<<"Name:"<<arr[i].m_Name<<" Age:"<<arr[i].m_Age<<endl;
   }
   
}


void test2()
{
    MyArray<Person> arr(10);
    Person p1("xcs",22);
    Person p2("xcsy",22);
    Person p3("geek",22);
    // 将数据插入数组
    arr.push_back(p1);
    arr.push_back(p2);
    arr.push_back(p3);
    // 打印person数组
    printPersonArray(arr);

    cout<<"arr_Person 大小:"<<arr.getSize()<<endl;
    cout<<"arr_Person 容量:"<<arr.getCapacity()<<endl;

   //cout<<"arr 的输出:"<<arr<<endl; // 这里不能用重载的<< 因为没有写 Person类的重载<< 
}


int main()
{
    system("chcp 65001");
    //test1();
    test2();
    system("pause");
    return 0;
}