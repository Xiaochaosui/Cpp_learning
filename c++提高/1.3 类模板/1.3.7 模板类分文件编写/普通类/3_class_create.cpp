#include <iostream>
#include <string>
#include "Person.h" // 导入你编写的类

using namespace std;

void test1()
{  

    // 分文件编写 普通类Person
    Person p("xcs",1);
    p.show();
}
//
int main()
{
   system("chcp 65001");
   test1();
   system("pause");
   return 0;
}