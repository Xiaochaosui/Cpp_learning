#include <iostream>
#include <cmath>

using namespace std;

// 4.5 string查找和替换

//1、查找
void test1()
{
    string s1 = "abcdefgde";
    int pos;
    // pos = s1.find("de");
    pos = s1.find("df");
    if(pos == -1)
    {
        cout<<"not find"<<endl;
    }
    else
    {
        cout<<"pos:"<<pos<<endl; // 返回的是参数字符串的第一个字符第一次出现所在的索引 未查到就返回-1 
    }
    pos = s1.rfind("de"); // 从右往左查的第一个 所出现的位置索引
    cout<<"pos:"<<pos<<endl; 
}
// 2、替换
void test2()
{
   string s1 = "xcs is a good man";
   s1.replace(0,3,"asdff");  // 从0号位置起的3个字符 替换为后面这个参数字符串所有，不管后面这个字符串有多长
   cout<<"s1:"<<s1<<endl;
}

void test3()
{   /*
    s.replace(pos, n, s1)     //用s1替换s中从pos开始（包括0）的n个字符的子串 
    */
    string s1 = "xcs is a good man";
    cout<<"s1:"<<s1<<endl;
    s1.replace(0,3,"xcsy");
    cout<<"s1_replace:"<<s1<<endl;
}
int main()
{
   system("chcp 65001");
//    test1();
   test3();
   system("pause");
   return 0;
}
