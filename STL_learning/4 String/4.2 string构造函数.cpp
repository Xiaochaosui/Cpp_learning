#include <iostream>
#include <string>

using namespace std;


// 4.2 string构造函数
void test1()
{
   string s1; //默认构造
   const char* str = "xcs is a good man";
   string s2(str); // 用char* 构造
   string s3(s2);   // 拷贝构造
   cout<<"s2:"<<s2<<endl;
   cout<<"s3:"<<s3<<endl;
   string s4(10,'a'); // 使用n个字符c初始化构造
   cout<<"s4:"<<s4<<endl;
}

int main()
{
   system("chcp 65001");
   test1();
   system("pause");
   return 0;
}
