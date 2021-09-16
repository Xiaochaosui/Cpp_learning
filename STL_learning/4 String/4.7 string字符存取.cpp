#include <iostream>
#include <cmath>

using namespace std;


// 4.7 string字符存取
void test1()
{
   string s1 = "xcs is a good man";
   for (int i = 0; i < s1.size(); i++)
   {
      cout<<s1[i]<<" ";   //通过[] 方式取字符
   }
   cout<<endl;

   for (int i = 0; i < s1.size(); i++)
   {
      cout<<s1.at(i)<<" ";//通过at() 方式取字符 
   }
   cout<<endl;
   // 修改单个字符
   s1[0] = 'Y';
   s1.at(1) = 'Y';
   cout<<"s1:"<<s1<<endl;
}

int main()
{
   system("chcp 65001");
   test1();
   system("pause");
   return 0;
}
