#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
//6.1  vector 排序

// vector 普通类型排序
void test2()
{   vector<int> a;
    a.push_back(10);
    a.push_back(2);
    a.push_back(30);
    a.push_back(16);
    a.push_back(14);
    for (vector<int>::iterator it = a.begin(); it != a.end(); it++){
         cout << *it << endl;
    }
    cout<<"===排序后==="<<endl; 
    sort(a.begin(), a.end());
     for (vector<int>::iterator it = a.begin(); it != a.end(); it++){
         cout << *it << endl;
    }
}
// vector中是自定义类型的排序
//自定义排序
struct student{
     char name[10];
     int score;
 };
 //用于 sort 排序用的 回调函数
bool comp(const student &a, const student &b){
     return a.score < b.score;
 }
void test3()
{
    vector<student> vectorStudents;
    int n = 5;
    while (n--){
        student oneStudent;
        string name;
        int score;
        cin >> name >> score;
        strcpy(oneStudent.name, name.c_str());
        oneStudent.score = score;
        vectorStudents.push_back(oneStudent);
    }
    cout << "==========排序前================" << endl;
    for (vector<student>::iterator it = vectorStudents.begin(); it != vectorStudents.end(); it++){
        cout << "name: " << it->name << " score: " << it->score << endl;
    }
    sort(vectorStudents.begin(),vectorStudents.end(),comp);
    cout << "===========排序后================" << endl;
    for (vector<student>::iterator it = vectorStudents.begin(); it != vectorStudents.end(); it++){
        cout << "name: " << it->name << " score: " << it->score << endl;
    }
}

//6.2 vector删除元素

//vector remove删除元素
void test5()
{
    vector<int> a;
    a.push_back(10);
    a.push_back(2);
    a.push_back(30);
    a.push_back(16);
    a.push_back(14);
    for (vector<int>::iterator it = a.begin(); it != a.end(); it++){
         cout << *it << endl;
    }
    cout<<"==="<<endl;
    /*  1、remove并不是删除，仅仅是移除，要加上erase才能完成删除。 
        2、remove并不是删除指定位置的元素，而移除所有指定的元素。 
        3、用algorithm代替成员函数不是一个好的选择 */
    remove(a.begin(),a.end(),30);
    for (vector<int>::iterator it = a.begin(); it != a.end(); it++){
         cout << *it << endl;
    }

}
//erase 删除vector元素
void test6()
{
    vector<int> a;
    a.push_back(10);
    a.push_back(2);
    a.push_back(30);
    a.push_back(16);
    a.push_back(14);
    for (vector<int>::iterator it = a.begin(); it != a.end(); it++){
         cout << *it << endl;
    }
    cout<<"==="<<endl;
    //和find 函数结合删除
    vector<int>::iterator index = find(a.begin(),a.end(),30);
    if(index != a.end())
    {
        a.erase(index);
    }
    // 遍历vector删除
    // for (vector<int>::iterator it = a.begin(); it != a.end(); it++){
    //     if(*it == 30)
    //     {
    //         it = a.erase(it);
    //     }
         
    // }
    for (vector<int>::iterator it = a.begin(); it != a.end(); it++){
        
         cout << *it << endl;
    }
    a.clear();
    cout<<"clear()"<<endl;
     for (vector<int>::iterator it = a.begin(); it != a.end(); it++){
        
         cout << *it << endl;
    }

   
}
// 输出vector
void outVec(vector<int> a)
{
    for (vector<int>::iterator it = a.begin(); it != a.end(); it++){
         cout << *it << endl;
    }
}

//6.3 两个vector合并

// 多个 合并vector
void test7()
{
    vector<int > a;
    vector<int > b;
    vector<int > c;
    a.push_back(1);
    b.push_back(2);
    c.push_back(3);
    //insert 方式
    // c.insert(c.end(),a.begin(),a.end());
    // c.insert(c.end(),b.begin(),b.end());
    // merge 方式
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    c.resize(a.size()+b.size());
    merge(a.begin(),a.end(),b.begin(),b.end(),c.begin());
    //merge方式要注意三点：
    /* 1、vec1,和vec2需要经过排序，merge只能合并排序后的集合，不然会报错。

    2、vec3需要指定好大小，不然会报错。

    3、merge的时候指定vec3的位置一定要从begin开始，如果指定了end，它会认为没有空间，当然，中间的位置我没有试，回头有空试一下。 */
    outVec(c);
}


// 6.4 vector 求最大最小元素
// 6.5 vector 求最大最小元素的索引
// vector中最大、小值
void test11()
{
   vector<int> a;
    a.push_back(10);
    a.push_back(2);
    a.push_back(30);
    a.push_back(16);
    a.push_back(14);
    cout<<"a:"<<a<<endl;
    ////获得 vector中最大、小值
    int max = *max_element(a.begin(),a.end());  
    int min = *min_element(a.begin(),a.end());
    // vector<int>::iterator m = max_element(a.begin(),a.end());
    // cout<<"m:"<<*m<<endl;
    //获得 vector中最大、小值的索引
    int max_index = distance(a.begin(),max_element(a.begin(),a.end()));
    int min_index = distance(a.begin(),min_element(a.begin(),a.end()));
    cout<<max<<"\n"<<min<<endl;
    cout<<max_index<<"\n"<<min_index<<endl;
}

// 6.6 vector <int> 类型 输出重载
// 重载vector的<< 运算符 用于直接输出 vector<int>
ostream& operator<< (ostream& cout,vector<int>& a)
{
    for(vector<int>::iterator it = a.begin();it != a.end();it++)
    {
        cout<<*it<<" ";

    }
    //cout<<"\n";
    return cout;
}
int main()
{
   system("chcp 65001");
   test2();
   system("pause");
   return 0;
}
