// 自己的通用数组类

#pragma once
#include <iostream>
using namespace std;



template<class T>
class MyArray
{
public:
    //有参构造 参数 容量
    MyArray(int capacity)
    {   cout<<"MyArry 的有参构造调用"<<endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];

    }

    // 拷贝构造

    MyArray(const MyArray& arry)
    {   cout<<"MyArry 的拷贝构造调用"<<endl;
        this->m_Capacity = arry.m_Capacity;
        this->m_Size = arry.m_Size;
        //this->pAddress = arry.pAddress; // 这是指针不能直接赋值   结束的时候会导致堆区的数据重复释放
        // 深拷贝
        this->pAddress =  new T[arry.m_Capacity];
        // 将arry中的数据都拷贝过来
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arry.pAddress[i];
        }
        
    }

    // operator= 防止浅拷贝问题     为了可以有 a = b =c 操作，所以返回自身
    MyArray& operator=(const MyArray& arry)
    {   cout<<"MyArry 的=调用"<<endl;
        // 首先判断原来堆区是否有数据 如果有则先释放
        if(this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
        // 深拷贝
        this->m_Size = arry.m_Size;
        this->m_Capacity = arry.m_Capacity;
        this->pAddress = new T[this->m_Capacity];
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arry.pAddress[i];
        }
        return *this;
    }
    // 尾插法
    void push_back(const T & val)
    {
       // 判断容量是否等于大小
       if (this->m_Capacity == this->m_Size)
       {
           return;
       }
       this->pAddress[this->m_Size] = val; // 数组末尾插入数据
       this->m_Size++; // 更新数组大小
    }
    // 尾删法
    void pop_back()
    {
       // 用户访问不到最后一个元素，即为尾删，逻辑删除
       if (this->m_Size == 0)
       {
           return ;
       }
       this->m_Size--;

    }
    // 通过下标的方式访问元素 重载[]
    // arry[0] arry[1] 还可以作为左值存在 即 arr[0]  =100;

    T& operator[](int index)
    {
        return this->pAddress[index]; // 这里没有考虑越界问题，可以自己加个判断
    }
    //重载cout<<
    // 这里要用友元 这里相当于是全局函数 访问 另一个MyArry里面的私有属性 pAddress 故要用友元
    friend ostream &operator<< (ostream& cout,const MyArray & arry) 
    {
        for (int i = 0; i < arry.m_Size; i++)
        {
            cout<<arry.pAddress[i]<<" ";
        }
        return cout; 
    }
    //返回数组的大小
    int getSize()
    {
        return this->m_Size;
    }
    // 返回数组的容量
    int getCapacity()
    {
        return this->m_Capacity;
    }
    // 析构
    ~MyArray()
    {   cout<<"MyArry 的析构函数调用"<<endl;
        if(this->pAddress !=NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }
private:
    T* pAddress; // 指针指向堆区开辟的真实数组
    int m_Capacity; // 通用数组的容量
    int m_Size;     // 数组的大小

};