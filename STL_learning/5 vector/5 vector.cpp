#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

void myPrint(int v)
{
   cout<<v<<endl;
}


// vector容器算法内置数据类型
void test1()
{  
    //创建vector容器，可以理解为一个数组
    vector<int> v;
    // 向容器中插入数据
    v.push_back(10);
    v.push_back(12);
    v.push_back(13);
    // 通过迭代器访问容器中的数据
    //第一种遍历方式
    vector<int>::iterator itBegin = v.begin();  //起始迭代器，指向容器中的第一个元素
    vector<int>::iterator itEnd = v.end();  //结束迭代器，指向容器中的最后一个元素的下个位置

    while (itBegin != itEnd)
    {
        cout<< *itBegin<<endl;
        itBegin++;
    }
    // 第二种遍历方式
    cout<<"// 第二种遍历方式"<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<endl;
    }

    //第3种遍历方式
    cout<<"// 第3种遍历方式"<<endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
         cout<< *it<<endl;
    }
    
    //第4种遍历方式,利用STL的遍历算法
    cout<<"// 第4种遍历方式"<<endl;
    for_each(v.begin(),v.end(),myPrint); //利用回调的技术 就是遍历v.begin() 到 v.end() 之间的每个元素去执行myPrint函数
    
}

int main()
{
   system("chcp 65001");
   test1();
   system("pause");
   return 0;
}
