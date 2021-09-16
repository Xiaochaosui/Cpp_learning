#include <iostream>
#include <cmath>

using namespace std;

// 4.8 string插入和删除

void test1()
{
    string s1 = "xcs is a man";
    s1.insert(9,"good "); //在索引9位置 插入 "good "
    cout<<"s1:"<<s1<<endl;
    // 删除
    s1.erase(0,3);
    cout<<"s1:"<<s1<<endl;
}

int main()
{
   system("chcp 65001");
   test1();
   system("pause");
   return 0;
}
