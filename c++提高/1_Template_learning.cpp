#include <iostream>
#include <cmath>

using namespace std;
// 1.2 模板
// 两个整型交换的函数
void swapInt(int &a,int &b)
{
   int t =a;
   a =b;
   b = t;
}
// 两个double交换的函数
void swapDouble(double &a,double &b)
{
   double t =a;
   a =b;
   b = t;
}
// 函数模板
template<typename T> // 声明一个模板，告诉编译器后面紧跟着的T 不要报错，T是一个数据类型
void mySwap(T &a,T &b)
{
   T t= a;
   a = b;
   b = t;
}

void test1()
{
    int a = 10;
    int b = 20;
   // swapInt(a,b);
   // 利用函数模板来交换
   // 两种方式使用函数模板
   // 1、自动类型推导
   //mySwap(a,b);
   // 2、显示指定类型
   mySwap<int>(a,b);
    cout<<"a="<<a<<",b="<<b<<endl;
    double c= 1.1;
    double d = 2.2;
    swapDouble(c,d);
    cout<<"c="<<c<<",d="<<d<<endl;
}
// 1.2.3 函数模板案例
/*
利用模板封装一个排序函数，对不同类型数组进行排序
从大到小，选择排序
分别利用char数组和int数组测试 
 */
// 交换
// template<class T>
// void mySwap(T &a,T &b)
// {
//    T t =a;
//    a = b;
//    b = t;
// }
//打印函数
template<typename T>
void pritnArray(T a[],int len)
{
   for (int i = 0; i < len; i++)
   {
      cout<<a[i]<<" ";
   }
   cout<<endl;
}

// 排序算法
template<typename T>
void mySort(T arr[],int len)
{
   for (int i = 0; i < len; i++)
   {
      int max = i;//认定最大值的下标
      for (int j = i+1; j < len; j++)
      {
         if (arr[max] < arr[j])
         {
            // 认定的最大值 比 遍历出的数值要小，说明j下边的元素才是真正的最大值
            max = j;
         }         
      }
      if (max !=i)
      {
         //交换max 和j 的元素
         mySwap(arr[max],arr[i]);
      }
      
   }
   
}

void test2()
{
   //测试char数组
   char chs[] = "sfdgdgs";
   int num = sizeof(chs)/ sizeof(char);
   mySort(chs,num);
   pritnArray(chs,num);
   //测试int数组
   int a[] = {1,4,67,8};
   num = sizeof(a)/sizeof(int);
   mySort(a,num);
   pritnArray(a,num);


}

// 1.2.4 普通函数与函数模板的区别
//普通函数
int myAdd(int a,int b)
{
   return a+b;
}

// 函数模板
template<typename T>
T myAdd1(T a,T b)
{
   return a+b;
}
void test3()
{
   int a =10;
   int b = 20;
   char c ='c';//ASCLL： a -> 97 
   cout<<myAdd(a,c)<<endl;
   // 1、自动类型推导
   //cout<<myAdd1(a,c)<<endl; //a,c 类型不同 会报错，因为不能做隐式类型转换
   // 2、显示指定类型
   cout<<myAdd1<int>(a,c)<<endl;
}
//  1.2.5 普通函数和函数模板的规则
void myPrint(int a,int b)
{
   cout<<"调用普通函数"<<endl;
}
template<class T>
void myPrint(T a,T b)
{
   cout<<"调用模板函数"<<endl;
}
template<class T>
void myPrint(T a,T b,T c)
{
   cout<<"调用重载的模板函数"<<endl;
}
void test4()
{
   int a =1;
   int b =2;
   // 如果函数模板和普通函数都可以实现，优先调用普通函数
   myPrint(a,b);
   // 空模板参数列表,强制调用模板函数
   myPrint<>(a,b);
   // 重载模板函数
   myPrint<>(a,b,11);
   //函数模板可以产生更好的匹配，优先调用函数模板
   myPrint(a,b,23);
   myPrint("a","c");
}
//1.2.6 模板的局限性
// 特定的数据类型 需要具体方式特殊实现
class Person
{
public:
   string m_name;
   int m_age;
   Person(string name,int age)
   {
      this->m_name = name;
      this->m_age = age;
   } 
};
template<class T>
bool myComp(T &a, T &b)
{
   if(a==b)
   {
      return true;
   }
   else
   {
      return false;
   }
   
}
// 利用具体化的Person 的版本实现 
template<> bool myComp(Person &a, Person &b)
{
   if(a.m_name==b.m_name && a.m_age == b.m_age)
   {
      return true;
   }
   else
   {
      return false;
   }
   
}
void test5()
{
   int a =1;
   int b =11;
   Person p1("xcs",18);
   Person p2("csy",19);
   
   bool res = myComp(a,b);
   if (res)
   {
      cout<<"a==b"<<endl;
   }
   else
   {
      cout<<"a != b"<<endl;
   }
  res = myComp(p1,p2);
   if (res)
   {
      cout<<"p1==p2"<<endl;
   }
   else
   {
      cout<<"p1 != p2"<<endl;
   }
   
   
}

int main()
{  
   system("chcp 65001");
   test5();
   system("pause");
   return 0;
}
