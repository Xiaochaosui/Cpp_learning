#include <iostream>
#include <cmath>

using namespace std;
// 模板
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

void test1()
{
    int a = 10;
    int b = 20;
    swapInt(a,b);
    cout<<"a="<<a<<",b="<<b<<endl;
    double c= 1.1;
    double d = 2.2;
    swapDouble(c,d);
    cout<<"c="<<c<<",d="<<d<<endl;
}
int main()
{
   test1();
   system("pause");
   return 0;
}
