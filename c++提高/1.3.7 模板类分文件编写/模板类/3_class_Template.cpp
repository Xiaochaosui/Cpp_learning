#include <iostream>
#include <string>

#include "Xcs.cpp" // 第一种方式，导入你编写的类，把整个类都写到.cpp文件中不需要.h 文件
 

using namespace std;

void test1()
{   //  分文件编写  模板类 Xcs
    Xcs<string,int> x("xcs",22); // 而直接这么调用是会报错的也就是上面提到的问题
    x.show();

    // 分文件编写 普通类Person
    // Person p("xcs",1);
    // p.show();
}
//
int main()
{
   system("chcp 65001");
   test1();
   system("pause");
   return 0;
}