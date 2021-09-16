#include <iostream>
#include <string>

using namespace std;


// 4.3 string赋值操作
void test1()
{
   string s1; //默认构造
   s1 = "xcs is a good man"; // char* 类型字符串 赋值给当前字符串s1
   cout<<"s1:"<<s1<<endl;
   string s2;  
   s2 = s1; //把字符串s1 赋值给当前字符串s2
   cout<<"s2:"<<s2<<endl; 
   string s3;
   s3 = 'a';   //字符赋值给当前字符串
   cout<<"s3:"<<s3<<endl;

   string s4;
   s4.assign("xcs is a good man!");
   cout<<"s4:"<<s4<<endl; //把字符串括号里面的参数char*  赋值给当前字符串s4
   string s5;
   s5.assign("xcs is a good man",5); //把字符串括号里面的参数 前5个字符赋值给当前字符串s5
   cout<<"s5:"<<s5<<endl;
   string s6;
   s6.assign(s5); //把字符串括号里面的参数string 赋值给当前字符串s6
   cout<<"s6:"<<s6<<endl; 
   string s7;
   s7.assign(5,'c'); //n个字符c 赋值给当前字符串s7
   cout<<"s7:"<<s7<<endl; 

}

int main()
{
   system("chcp 65001");
   test1();
   system("pause");
   return 0;
}
