#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// 4.4 字符串拼接
void test1()
{
    string s1 = "xcs ";
    s1 += " is a good man";  //重载+=操作符
    cout<<"s1:"<<s1<<endl;
    s1 += "!";   //重载+=操作符
    cout<<"s1:"<<s1<<endl;
    string s2 = "@SAIC";  
    s1 += s2;       //重载+=操作符
    cout<<"s1:"<<s1<<endl; 

    string s3 = "xcs";
    s3.append(" loves basketball"); // 将字符串s连接到当前字符串结尾
    cout<<"s3:"<<s3<<endl; 
    s3.append(" love LOL",4);  // 将字符串s的前n个字符连接到当前字符串结尾
    cout<<"s3:"<<s3<<endl; 
    string s4 = "&xcsy";
    s3.append(s4);
    cout<<"s3:"<<s3<<endl;  // 将字符串s连接到当前字符串结尾
    string s5 = "hello@@";
    s3.append(s5,2,4);// 将字符串s中从pos开始的n个字符连接到字符串末尾
    cout<<"s3:"<<s3<<endl;
}

int main()
{
   system("chcp 65001");
   test1();
   system("pause");
   return 0;
}
