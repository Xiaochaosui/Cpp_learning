#include <iostream>
#include <cmath>

using namespace std;

// 4.6 string字符串比较
/* 字符串比较是按字符的ASCII码进行对比

 = 返回 0
 > 返回 1
 < 返回 -1 */
void test1()
{
    string s1 = "xcs";
    //string s2 = "xcs";
    string s2 = "ycs";
    // string s2 = "ucs";
    if(s1.compare(s2) == 0)
    {
        cout<<s1<<" == "<<s2<<endl;
    }
    else if(s1.compare(s2) == -1)
    {
        cout<<s1<<" < "<<s2<<endl;
    }
    else if(s1.compare(s2) == 1)
    {
        cout<<s1<<" > "<<s2<<endl;
    }


}

int main()
{
   system("chcp 65001");
   test1();
   system("pause");
   return 0;
}
