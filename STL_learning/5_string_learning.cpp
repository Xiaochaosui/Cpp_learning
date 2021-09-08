#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

// 5.3 字符串替换
//字符串 替换
void test1()
{   /*
    s.replace(pos, n, s1)     //用s1替换s中从pos开始（包括0）的n个字符的子串 
    */
    string s1 = "xcs is a good man";
    cout<<"s1:"<<s1<<endl;
    s1.replace(1,3,"xcsy");
    cout<<"s1_replace:"<<s1<<endl;
}