#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// 4.9 string字串获取
void test1()
{
   string s1 = "xcs is a good man";
   string s2;
   s2 = s1.substr(9,4);//截取 "good" //返回由pos开始的n个字符组成的字符串
   cout<<"s2:"<<s2<<endl;

   string email = "chaosuixiao@gmail.com";
   //从邮箱地址中获取 用户名信息

   int pos = email.find("@");
   string name;
   name = email.substr(0,pos);
   cout<<"name:"<<name<<endl;
}

int main()
{
   system("chcp 65001");
   test1();
   system("pause");
   return 0;
}
