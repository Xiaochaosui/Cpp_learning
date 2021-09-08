[TOC]

# C++_learning

## 1 C++初识

### 1.1 变量

变量存在的意义：方便我们管理内存空间

```C++
#include<iostream>
using namespace std;
int main()
{
    int a;
    a = 10;
    cout <<"a="<<a<<endl;

    system("pause");
    return 0;
}

```

### 1.2 常量

c++定义常量的方式

​	1、**#define 宏常量**：

```c++
#define 常量名 常量值
#define Day 7
```

​			文件上方定义，且不可修改，一旦修改就会报错

​	2、**const 修饰的变量**	：

```c++
const int month = 12
```

​		const修饰的变量也成为常量，不能被修改

### 1.3 关键字(标识符)

**作用**:关键字是C++中预保留的词

C++关键字：

​	不要用关键字给变量或者常量起名称，否则会产生歧义；

​	上网查一下；

### 1.4 标识符命名规则

- 标识符不能是关键字
- 标识符只能由字母、数字、下划线组成
- 第一个字符必须为字母或下划线
- 标识符中字母区分大小写

advice：最后能做到见面知意

## 2 数据类型

**意义**：给变量分配合适的内存空间

### 2.1 整型

**作用**：表示整数类型数据

不同的整型表示方式如下：**区别在于所占内存空间不同；**

| 数据类型  | 占用空间                                      | 取值范围        |
| --------- | --------------------------------------------- | --------------- |
| short     | 2字节(2*8=16)                                 | （-2^15~2^15-1) |
| int       | 4字节                                         | （-2^31~2^31-1) |
| long      | windows为4字节，linux为4字节(32位)，8字节(64) | （-2^31~2^31-1) |
| long long | 8字节                                         | （-2^63~2^63-1) |

### 2.2 sizeof关键字

**作用：** 利用sizeof求数据类型的内存大小(单位字节)

short <int <=long <=long long

### 2.3 实型(浮点型)

**作用:**表示小数

1.  单精度float
2. 双精度double

**区别:**有效数字范围不同

```c++
#include <iostream>
using namespace std;
int main()
{
    float f1 = 3.1415926f;
    double d1 = 3.1415926;
    // 默认情况下 输出一个小数，会显示出6为有效数字
    cout <<"f1="<<f1<<endl;
    cout <<"d1="<<d1<<endl;
    cout <<"size float "<<sizeof(float)<<endl; //4字节
    cout <<"size double "<<sizeof(double)<<endl; // 8字节
    cout << "Hello world!" << endl;
    //科学计数法
    float f2 = 3e2; //3*10^2
    float f3 = 3e-2; //3*10^-2
    cout<<f2<<endl;
    cout<<f3<<endl;
    return 0;
}
```

### 2.4 字符型

**语法:** char ch = 'a';

注意1：单引号将字符括起来，不要用双引号；

注意2：单引号内只有一个字符，不是字符串；

- c和c++中的字符型变量只占用1个字节
- 字符型变量并不是把字符放在内存存储，而是将对于的ASCII码存储

### 2.5 转义字符

**作用：**用于一些不能显示出来的ascll字符

### 2.6 字符串型

**两种风格**

1. c 风格字符串:char 变量名[] = "字符串值"

2. C++ ：string 变量名 = "字符串值"

   加头文件，#include <string>
   
3. **相应的字符串函数**，

   - strlen(str) 返回字符串的长度
   - strcpy(s1,s2)复制s2到s1
   - strcmp(s1,s2) 如果s1和s2相同则返回0，如果s1小于s2则返回小于0，反之大于0
   - strchr(s1,ch) 返回一个指针，指向字符串s1中字符ch第一次出现的位置
   - strstr(s1,s2) 返回一个指针，指向字符串s1中s2第一次出现的位置

### 2.7 布尔类型bool

代表真或者假的值

bool类型占1个字节大小

### 2.8 数据的输入

**关键字：** cin

**语法：**cin>>变量

```c++
  int a;
   cin >>a;
   cout <<a<<endl;
```

## 3 运算符

### 3.1 算数运算符

| 运算符 | 术语                      | 示例       | 结果     |
| ------ | ------------------------- | ---------- | -------- |
| %      | 取模，取余                | 10%3       | 1        |
| ++     | 前置递增                  | a=2;b=++a; | a=3;b=3; |
| ++     | 后置递增                  | a=2;b=a++; | a=3;b=2; |
| --     | 前置递减,先自减再赋值给b  | a=2;b=--a; | a=1;b=1; |
| --     | 后置递减，先赋值给b再自减 | a=2;b=a--; | a=1;b=2; |

不可以对0取模，两个小数不可以取模运算

### 3.2 逻辑运算符

| 运算符 | 术语 | 示例   | 结果                                                   |
| ------ | ---- | ------ | ------------------------------------------------------ |
| ！     | 非   | !a     | 取反                                                   |
| &&     | 与   | a&&b   | 如果a和b都为真则a&&b为真，只要有一个为假则a&&b为假     |
| \|\|   | 或   | a\|\|b | 如果a和b都为假则a\|\|b为假，只要有一个为真则a\|\|b为真 |

在c++中除了0都为真

## 4 程序流程结构

三种程序运行结构：顺序结构，选择结构，循环结构

### 4.1 选择结构

#### 4.1.1 if语句

- 单行格式if语句 `if(条件) {条件满足执行的语句}`
- 多行格式if语句
  - `if(条件){条件满足执行的语句} else{条件不满足满足执行的语句}`
- 多条件if语句
  - `if(条件1){条件1满足执行的语句} else if(条件2){条件2满足满足执行的语句}...else{条件都不满足满足执行的语句}`

#### 4.1.2 三目运算

**作用:** 实现简单的运算符判断

**语法:** 表达式1?表达式2:表达式3

​	如果表达式1的值为真，执行表达式2，并返回表达式2的结果；

​	如果表达式1的值为假，执行表达式3，并返回表达式3的结果；

#### 4.1.3 switch语句

和C语言一样

```c++
switch(变量)
{
   case1:
        代码块1
        break //如果没有break 则会执行后续的code
   case2:
        代码块2
   default:
        代码块3
}
```

**if和switch区别**

​	switch 缺点 ：判断时候只能判断整型或者字符型，不可以是一个区间。

​	switch 优点：结构清晰，执行效率高。

case中没有break，程序会一直执行下去。

### 4.2 循环结构

#### 4.2.1 while循环

**语法:**`while(条件){条件满足执行循环语句}`

#### 4.2.2 do...while循环

**语法:**`do{循环语句} while(循环条件);`

**Attention:**与while区别在于do...while会先执行一次循环语句，再判断循环条件。

#### 4.2.3 for循环

**语法：**`for(int i=0;i<10;i++){执行的循环代码}`

### 4.3 跳转语句

**作用:**可以无条件跳转语句

**语法：**`goto 标记;`

**解释:**如果标记的名称存在，执行goto语句，会跳转到标记的位置

```c++
int main()
{
    cout <<1<<endl;
    cout <<2<<endl;
    goto FLAG;
    cout <<3<<endl;
    cout <<4<<endl;
    FLAG:
    cout <<5<<endl;
    return 0;
}
```

## 5 数组

### 5.1 一维数组

一维数组3种定义方式:

1. `int a[len];`
2. `int a[3]={1,2,3};`
3. `int a[]={1,2,3};`

### 5.2 二维数组

二维数组的4种定义方式:

1. `int a[3][4];`
2. `int a[3][4]={{1,2,3,4},{1,2,3,4}}`;
3. `int a[3][5]={1,2,3,4}`;
4. `int a[][2]={1,2,3,4};`

## 6 函数

### 6.1 函数定义

1. 返回值类型  int
2. 函数名          add
3. 参数类型     (int n1,int n2)
4. 函数体语句   函数的代码块
5. return 表达式   return res;

### 6.2 函数的调用

 这个不用说了吧，把公式拿过来用而已；

### 6.3 值传递

值传递的时候，形参改变不会影响实参

### 6.4 函数的常见样式

4种：

- 参数和返回值排列组合

### 6.5 函数声明

在使用函数之前告诉 我要用这个函数了。

声明可以有多次，定义只可以有一次

### 6.6 分文件编写

**作用：**让代码结构更加清晰

函数文件编写一般4个步骤:

1. 创建.h文件
2. 创建.cpp源文件
3. 在头文件写函数的声明
4. 在源文件写函数的源定义

## 7 指针

同C语言

## 8 结构体

同C语言

## 9 头文件

### 9.1 #define与#undef的使用

#define，无参宏定义的一般形式为：#define 标识符 字符串（例：#define Max 10）。define函数定义一个常量。常量类似变量，不同之处在于：在设定以后，常量的值无法更改。常量值只能是字符串或者
数字。
#undef ，就是取消一个宏的定义，之后这个宏所定义的就无效；但是可以重新使用#define 进行定义。
1.在一个程序块中用完宏定义后，为防止后面标识符冲突需要取消其宏定义.

#undef就是取消一个宏的定义，之后这个宏所定义的就无效；

但是可以重新使用#define 进行定义。

# C++进阶

## 1 内存分区模型

c++执行，将内存划分为4各区域:

- 代码区:存放函数体的二进制代码，由OS进行管理的
- 全局区：存放全局变量和静态变量以及常量
- 栈区:由编译器自动分配释放，存放函数的参数值、局部变量等
- 堆区:由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收

**内存区的意义：**不同区域存放的数据有不同的生命周期；

### 1.1 程序运行前

**代码区:**

​	存放CPU执行的机器指令

​	代码区是**共享**的,共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可

​	代码区是**只读**的,使其只读的原因是防止程序意外地修改了它的指令

**全局区:**

​	全局变量和静态变量存放在此

​	全局区还包含了常量区、字符串常量和其他常量（局部常量不在全局区,const int a=10; 不在全局区）

​	该区域的数据在程序结束后由操作系统释放

总结:

- C++ 在程序运行钱分为全局区和代码区
- 代码区特点是共享和只读
- 全局区中存放全局变量，静态变量，常量
- 常量区中存放const修饰的全局变量 和 字符串常量

### 1.2 程序运行后

**栈区:**

​	由编译器自动分配释放，存放函数的参数值、局部变量等

​	**Pay Attention**：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放;

**堆区:**

​	由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收

​	在C++中主要利用new在堆区开辟内存

### 1.3 new运算符

c++中**new**操作符在堆区开辟数据

堆区开辟的数据由程序员手动开辟手动释放释放利用操作符**delete**

语法：`new 数据类型`

利用new创建的数据，会返回该数据对应的类型的指针

```c++
//开辟堆区空间
//开辟数组空间
int *p = new int a[10];
//释放数组
delete[] a;
//开辟变量空间
int *q = new int a;
//释放变量
delete a;
```

## 2 引用

### 2.1 引用的适用

**作用:** 给变量起别名
**语法**: `数据类型 &别名 = 原名`

### 2.2 引用的注意事项

- 引用必须初始化
  - 不能写 `int &b;`
- 引用一旦初始化后不能改变
  - 也就是说 刚开始 b是a的别名了，后来不可以把b变成c的别名

### 2.3 引用做函数参数

**作用**：函数传参时，可以利用引用的技术让形参修饰实参

**优点**:简化指针修改实参

### 2.4 引用做函数的返回值

- 不要返回局部变量的引用
- 如果函数的返回值是一个引用则函数的调用可以为左值

### 2.5 引用的本质

**本质**：引用的本质实现是一个指针常量

```c++
int&ref = a;//等价于下面这行代码
int* const ref = &a;// 指针常量 说明指向不可改，也就是说引用不可改
ref = 20;//内部发现ref是一个引用则自动转换为 *ref = 20;
```

### 2.6 常量引用

**作用：**常量引用主要用来修饰形参，防止误操作

**使用场景**：在函数形参列表中，可以加const修饰形参，防止形参改变实参

```c++
int &ref = 10;//引用本身是需要一个合法的空间，因此这一行是错误的，但是在前面加上一个const就可以了
const int &ref = 10;// 等价于 int t = 10;cosnt int &ref = t;
```

## 3 函数提高

### 3.1 函数默认参数

函数列表的形参可以由默认值的

**语法**：`返回值类型 函数名(参数=默认值){函数体}`

**Pay Attention：**

-  如果某个位置已有了默认参数，那么从这个位置往后，从左到右都必须有默认值
- 如果函数的声明有默认参数，函数实现就不能有默认参数；声明和实现只能有一个有默认参数；

### 3.2 函数占用参数

函数形参列表里可以有占位参数，用来占位，调用函数时必须填补该位置

**语法**：`返回值类型 函数名(数据类型){函数体}`

```c++
void func(int a,int)
{	
    //函数体
} //这个函数就必须要两个参数才可以调用
```

### 3.3 函数重载

#### 3.3.1 函数重载的概述

**作用**：函数名相同，提高复用性

**函数重载满足的条件：**

- 在同一个作用域下

- 函数名称相同

- 函数参数类型不同，或者个数不同，或者顺序不同

  ```C++
  void f2()
  {
      cout<<"f2用用"<<endl;
  }
  void f2(int a)
  {
      cout<<"f2用用!!!"<<endl;
  }
  ```

**Pay Attention:**函数的返回值不可作为函数重载的条件(int 类型和 void类型不能重载)

#### 3.3.2 函数重载注意事项

- 引用作为重载的条件
- 函数重载碰到默认参数(出现二义性)



## 4 C++ 类&对象

**面向对象三大特性:封装、继承、多态**



![img](https://www.runoob.com/wp-content/uploads/2015/05/cpp-classes-objects-2020-12-10-11.png)



​	对象蓝图；

- 在类的定义里面有变量声明和函数声明，也可以在类里面定义函数；

- 类成员函数的定义在类的外面写格式(**使用范围解析运算符::**)如下:

- ```c++
  函数类型 类名::函数名字(参数):
  {
      函数体
  }
  ```

**需要注意的是，私有的成员和受保护的成员不能使用直接成员访问运算符 (.) 来直接访问**

### 4.1 封装

**封装的意义：**

- 将属性和行为作为整体
- 将属性和行为加以权限控制

**语法：**`class name{内容};`

#### 4.1.1 权限

1. pubilic 公共权限  成员 类内可以访问，类外可以访问
2. protected 保护权限  成员 类内可以访问， 类外不可以访问   儿子可以访问父亲中的保护内容
3. private 私有权限  成员   类内可以访问，类外不可以访问     儿子不可以访问父亲中私有内容

#### 4.1.2 struct和class区别

- struct 默认权限为共有
- class 默认权限为私有 

#### 4.1.3 成员属性设为私有

**优点**：

- 将所有成员设置为私有们可以自己控制读写权限
- 对于写权限，我们可以检测数据的有效性

### 4.2 对象的初始化和清理

- 类似恢复出厂设置
- 清理数据

#### 4.2.1 构造函数和析构函数

对于**初始化和清理**是两个非常重要的**安全问题**

- ​	一个对象或者变量没有初始状态，对其使用后果是未知

- ​	同样的使用完一个对象或变量，没有及时清理，也会造成一定的安全问题

**解决以上问题:构造函数和析构函数**

​	这两个函数是编译器自动调用，完成对象初始化和清理工作；**对象的初始化和清理工作是编译器强制我们要做的事情，因此如果我们不提供构造和析构，编译器会提供编译器提供的构造函数和析构函数是空实现。**

1. **构造**函数：主要作用于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无须手动调用。
2. **析构**函数：主要作用于对象销毁前系统自动调用，执行清理工作。

**构造函数语法：**`类名(){函数体}`

1. 构造函数，没有返回值也不写void
2. 函数名称和类名相同
3. 构造函数可以有参数，因此发生重载
4. 程序在调用对象时候会自动调用构造函数，无需手动调用，而且只会调用一次

**析构函数语法：**`~类名(){函数体}`

1. 析构函数，没有返回值也不写void
2. 函数名称与类名相同，前面加上~
3. 析构函数不可以有参数，因此不发生重载
4. 程序对象销毁前会自动调用析构，无需手动调用，而且只会调用一次

#### 4.2.2 构造函数的分类及调用

**两种分类方式：**

​	按参数分：有参构造和无参构造

​	按类型分：普通构造和拷贝构造

```C++
class Person
{
public:
    Person()
    {
        cout<<"构造函数调用"<<endl;
    }
    // 有参构造
    Person(int a)
    {
        cout<<"构造函数调用"<<endl;
    }
    //拷贝构造函数
    Person(const Person &p)
    {   //将传入的对象的属性 拷贝到我身上
        age = p.age;
    }
}
```

​	

**调用：**

1. 括号法 
2. 显式法 
3. 隐式转化法

```C++
Person p1;
//括号法 
Person p(10);  // 有参构造 
Person p(p1);  // 拷贝构造
//显式法 
Person p2 = Peseson(10);//有参构造(类似于Java)；
Person p2 = Peseson(p1);//拷贝构造；
// 匿名对象 特点：当前执行结束，立刻释放对象
Person(10);
Person(p1);//不要利用拷贝构造函数 初始化匿名对象
//隐式转化法
Person p3 = 10;//相当于写了 Person p3 = Peseson(10)
Person p3 = p1;//拷贝构造
```

**Pay Attention:**

- 调用默认构造函数(`Person p;`)时候，不要加()，因为编译器会认为他是一个函数声明，不会认为在创作对象；
- 不要利用拷贝构造函数 初始化匿名对象

#### 4.2.3 拷贝构造函数调用时机

拷贝构造函数调用的三种情况:

- 使用一个已经创建完毕的对象来初始化一个新对象
- 值传递的方式给函数参数传值；(意思就是 把类的对象作为参数传递给函数时 会自动调用拷贝构造函数)
- 以值方式返回局部对象；(意思就是 把类的对象作为函数的返回值 会自动调用拷贝构造函数)

#### 4.2.4 构造函数的调用规则

**默认情况，C++编译器至少给一个类添加3个函数**

- 默认构造函数
- 默认析构函数
- 默认拷贝构造函数**，对属性值进行值拷贝**

构造函数调用规则：

- 如果用户定义有参构造函数，c++不在提供默认无参构造，但是会提供默认拷贝构造
- 如果用户定义了拷贝构造函数，c++不会提供其他构造函数

#### 4.2.5 深拷贝和浅拷贝

**浅拷贝**：简单的赋值拷贝操作，对于拷贝构造函数编译器默认实现的是浅拷贝

​	**问题：**

​		浅拷贝会造成堆区的内存重复释放

​	**解决：**

​		利用深拷贝解决

​	

**深拷贝：**在堆区重新申请内存空间，进行操作

#### 4.2.6 初始化列表

语法:`构造函数():属性1(v1),属性2(v2)....{}`

```C++
//初始化列表初始化属性
    Person(int a,int b ,int c):A(a),B(b),C(c)
    {
    }
```

#### 4.2.7 类对象作为类成员

C++类中的成员是另一个类的成员，称为 对象成员

```C++
class A
{
public:
    A()
    {
        cout<<"A的构造函数"<<endl;
    }
    ~A()
    {
        cout<<"A的析构函数"<<endl;
    }
};
class B
{
public:
    A a;
    B()
    {
        cout<<"B的构造函数"<<endl;
    }
    ~B()
    {
        cout<<"B的析构函数"<<endl;
    }
};

```

B 类中有对象A作为成员，A为对象成员

**创建B对象时，A与B的构造和析构顺序怎样的？**

​	先执行A 的构造函数 再执行B的构造函数，然后执行B的析构函数 再执行A析构函数；

#### 4.2.8 静态成员

静态成员就是在成员变量或者函数前面加上关键字static，成为**静态成员**

分类：

- 静态成员变量
  - 所有对象共享同一份数据
  - 在编译阶段分配内存
  - 类内声明，类外初始化

- 静态成员函数
  - 所有对象共享同一个函数
  - 静态成员函数只能访问静态成员变量
  - 可以通过对象访问也可以通过类名访问
  - 也是有权限的(public & private)

```

```

### 4.3 C++对象模型和this指针

#### 4.3.1 成员变量和成员函数分开存储

只有**非静态成员变量才属于**类的对象上

空对象大小为 1字节，C++编译器会给每个空对象分配一个字节空间，是为了区分空对象占内存的位置

- 静态成员变量 **不**属于类对象上
- 静态成员函数 **不**属于类对象上
- 非静态成员函数 **不**属于类的对象上

#### 4.3.2 this指针概念

如何区分那个对象是调用自己的？

用this指针！**this指针指向被调用的成员函数所属的对象！**

this指针是隐含每一个非静态成员函数内的一种指针

this指针不需要定义，直接使用即可

this指针的**用途**(解决什么问题)：

- 当形参和成员变量同名时，可用this指针来区分(解决变量或者函数名称冲突)
- 在类的非静态成员函数中返回对象本身，可使用return *this

#### 4.3.3 空指针访问成员函数

空指针可以调用成员函数，注意看有没有this指针

```c++
class Person
{
  void f1()
  {
      cout<<"aa";
  }
    void f2()
    {
        cout<<age<<endl;
    }
    int age;
};
int main()
{
    Person *p = NULL;
    p->f1();//可执行   空指针调用函数
    p->f2();//报错，因为这个函数里面要调用age变量 ，即this->age；而p是一个null，没有age
}
```

#### 4.3.4 const修饰成员函数

**常函数：**

- 成员函数后加const后我们称这个函数为**常函数** 
  - void f1() const{函数体}
  - 实际上时修饰this指向，让this指向的值也不可以修改 变成const Person * const this;
- 常函数内不可以修改成员属性
- 成员属性声明时加关键字mutable后，在常函数中依然可以修改

**常对象：**

- 声明对象前加const称为常对象
- 常对象只能调用常函数

### 4.4 友元

客厅(public)，卧室(private)

但是私有属性，也想让一些特殊的类或者函数进行访问，就要用到友元技术；

友元的目的：

​	让一个函数或者类访问另一个类的私有成员；

友元的关键字：`friend`

友元的三种**实现**：

- 全局函数做友元
- 类做友元
- 成员函数做友元

#### 4.4.1 全局函数做友元

在要被访问的类里面 加上全局函数的声明，`friend void f1();`

#### 4.4.2  类做友元

在要被访问的类里面 加上类的声明，`friend class 类名;`

也就是被加上友元的类里面的所以函数都可以访问  那个类

#### 4.4.3 成员函数做友元

在要被访问的类里面 加上类的成员函数声明，`friend  类名::成员函数();`

只有被加上友元的成员函数可以访问那个类，其他的函数不可访问。

### 4.5 运算符重载

**概念**：对已有的运算符重载进行定义，赋予其另一种功能，以适应不同的数据类型

对于内置的数据类型，编译器知道如何运算；

如：int 

通过自己写成员函数，实现两个对象相加属性后返回新的对象

#### 4.5.1 加号运算符重载

```C++
//通过成员函数重载+号
class Person{
    Person operator+ (Person &p)
{
    Person t;
        t.a = this->a + p.a;
    return t;
}
public:
    int a;	
}
// Person p3 = p1.operator+(p2); 等价于 Person p3= p1 + p2;

//通过全局函数重载+号
    Person operator+ (Person &p,Person &q)
{
    Person t;
        t.a = q->a + p.a;
    return t;
}
// Person p3 = operator+(p1,p2); 等价于 Person p3= p1 + p2;
```

**运算符重载也可以发生函数重载**；

**Pay Attention：**

- 对于内置的数据类型的表达式的运算符是不可以改变的 如 int + int
- 不要滥用运算重载符

#### 4.5.2 左移运算符重载

**作用:** 可以输出自定义的类型

`<<`

```C++
class Person
{
public:
    //成员函数 左移运算符 p.operator<<(cout); 简化:p<<cout;
    //所以一般不用成员函数重载<<运算符，因为无法实现 cout<<p;
//    void operator<<(Person& p)
//    {
//
//    }
    int m_a;
    int m_b;
};

//全局函数重载
ostream& operator<< (ostream &cout,Person &p)//本质 operator<<(cout,p) 简化cout <<p;
{
    cout<<"m_a="<<p.m_a<<" m_b="<<p.m_b;
    return cout;
}
void test()
{

    Person p;
    p.m_a = 10;
    p.m_b = 20;
    cout<<p<<endl; //endl 又会报错,因为没有那个链式调用 所以 把重载运算符函数改为 有返回值的函数
}
int main()
{
    test();
    cout << "Hello zht!" << endl;

    return 0;
}

```

#### 4.5.3 递增运算符重载

**作用**:通过重载递增运算符，实现自己的整型数据

```C ++
class MyInterger
{

    friend ostream& operator<< (ostream&out,MyInterger myint);
    friend MyInterger& operator++(MyInterger& myint);

public:
    MyInterger()
    {
        m_Num = 133;
    }
    //成员函数 重载前置++运算符
//    MyInterger& operator++()
//    {
//        ++m_Num;
//
//        return *this;
//    }
    //重载后置++运算符
    //int 代表占位参数 用于区分前置和后置递增
    MyInterger operator++(int)
    {
        MyInterger t = *this;
        m_Num++;
        return t;
    }
private:
    int m_Num;
};
// 全局函数 重载 <<运算符
ostream& operator<< (ostream&out,MyInterger myint)
{
    out<<myint.m_Num;

    return out;
}
//全局函数 重载前置++运算符
MyInterger& operator++(MyInterger &myint)
{
    ++myint.m_Num;

    return myint;
}

//测试 前置++
void test1()
{
    MyInterger myint;
    //本质
    //cout<<"sdf"<<myint.operator++().operator++()<<endl;
    cout<<++myint<<endl; //简化
    cout<<++(++myint)<<endl;
    cout<<myint<<endl;

}
//测试 后置++
void test02()
{
    MyInterger i;
    //i.m_Num = 100;
    cout<<i++<<endl;
    cout<<i<<endl;
}

int main()
{
   // test1();
   test02();
    cout << "Hello zht!" << endl;
    return 0;
}

```

总结：前置++返回引用,后置++返回 值



#### 4.5.4 赋值运算符重载

**默认情况，C++编译器至少给一个类添加4个函数**

- 默认构造函数
- 默认析构函数
- 默认拷贝构造函数，对属性值进行值拷贝
- 赋值运算符 operator= 对属性进行值拷贝

**如果类中有属性指向堆区，做赋值操作时会出现深浅拷贝问题**

```C++
/赋值运算符重载
class Cat
{
public:
    Cat(int age)
    {
        m_age = new int(age);

    }
    ~Cat()
    {
        if(m_age !=NULL)
        {
            delete m_age;
        }
    }
    //重载运算符
    Cat& operator=(Cat &c)
    {
        //应该先判断C是否有属性在堆区，如果有则释放感觉 再深拷贝
        if(m_age !=NULL)
        {
            delete m_age;
            m_age= NULL;
        }
        //深拷贝
        m_age = new int(*c.m_age);
        return *this;
    }
    int *m_age;
};

void test3()
{
    Cat c(12);
    Cat c1(32);
    Cat c2(23);
    c2 = c1= c;//赋值操作   浅拷贝 堆区内存重复释放 程序崩溃！ 用深拷贝解决此问题
    cout<<"age:"<<*c.m_age<<endl;
    cout<<"age:"<<*c1.m_age<<endl;
    cout<<"age:"<<*c2.m_age<<endl;

}
```

#### 4.5.5 关系运算符重载

**作用：**重载关系运算符，可以让两个自定义类型对象进行对比

#### 4.5.6 函数调用运算符重载(仿函数)

- 函数调用符() 重载
- 由于重载后使用的方式非常像函数的调用，因此称为仿函数
- 仿函数没有固定的写法，非常灵活 

```C++
class MyPrint
{
public:
    //重载函数调用运算符
    void operator()(string txt)
    {
        cout<<txt<<endl;
    }
};

void test4()
{
    MyPrint pr;
    pr("hellow ");//由于使用起来很像函数调用，因此称为仿函数，
    //匿名函数对象
    MyPrint()("helloworld");
}
```

### 4.6 继承

**继承是面向对象三大特性之一**

#### 4.6.1 继承的语法

```c++
class Son:public Father
{
    
};
```

**好处:减少重复的代码**

#### 4.6.2 继承方式

**三种**

- 公共继承
- 保护继承
- 私有继承

### 4.7 多态





【未完待续】







## 5 文件的操作

c++文件操作需要包含头文件`<fstream>`

文件类型分两种：

1. 文本文件  -文件以文本的ASCLL码形式存储在计算机中
2. 二进制文件 -文件以文本的二进制形式存储在计算机中

**操作文件的三大类：**

1. ofstream：写操作
2. ifstream：读操作
3. fstream：读写操作

### 5.1 文本文件

#### 5.1.1 写文件

步骤如下：

1. 包含头文件  `#include<fstream>`
2. 创建流对象 `ofstream ofs;`
3. 打开文件 `ofs.open("文件路径",打开方式);`
4. 写数据 `ofs<<"写入数据";`
5. 关闭文件 `ofs.close();`

文件打开方式:

| 打开方式    | 解释                            |
| ----------- | ------------------------------- |
| ios::in     | 为读文件而打开文件              |
| ios::out    | 为写文件打开文件                |
| ios::ate    | 初始位置:文件末尾               |
| ios::app    | 追加方式写文件                  |
| ios::trunc  | 如果文件已存在 则 先删除 在创建 |
| ios::binary | 二进制方式                      |

注意:文件打开方式可以配合使用，利用你|操作符

如:`ios::binary | ios::out`

#### 5.1.2 读文件

步骤如下：

1. 包含头文件  `#include<fstream>`
2. 创建流对象 `ifstream ifs;`
3. 打开文件 `ifs.open("文件路径",打开方式);`
4. 写数据 `ifs<<"写入数据";`
5. 关闭文件 `ifs.close();`

```c++
//读取方式: 逐词读取, 读词之间用空格区分
void readFile1(string path)
{
    fstream f;
    f.open(path);
    string s;
    while(f>>s)  // 把文件内容写入字符串s中 
    {
        cout<<s<<endl;
    }
    f.close();
}
//读取方式: 逐行读取, 将行读入字符数组, 行之间用回车换行区分
void readFile2(string path)
{
    fstream f;
    f.open(path);
    const int LINE_LENGTH = 100;
    char str[LINE_LENGTH];
    string s;
    while(f.getline(s, LINE_LENGTH))  // 把文件内容写入字符数组s中 
    {
        cout<<s<<endl;
    }
    f.close();
}
//读取方式: 逐行读取, 将行读入字符串, 行之间用回车换行区分

void readFile3(string path)
{
    fstream f;
    f.open(path);
    string s;
    while(getline(f,s))  // 把文件内容写入字符串s中 
    {
        cout<<s<<endl;
    }
    f.close();
}
```



### 5.2 二进制文件

打开方式指定为 `ios::binary`

#### 5.2.1 写文件

步骤同上

#### 5.2.2 读文件

同上

以二进制的方式读取数据

`ifs.read((char*) &p,siezeof(p));`

# C++ 提高编程

泛型编程

## 1 模板

### 1.1 模板的概念

模板就是建立通用的摸具，大大提高复用性



### 1.2 函数模板

- C++一种编程思想称为***泛型编程***，注意利用技术就是模板
- c++提高两种模板机制：**函数模板和类模板**

#### 1.2.1 函数模板语法

函数模板作用：

建立一个通用函数，其函数**返回值类型**和**形参类型**可以**不具体制定**，用一个虚拟的类型来代表



语法

```c++
template<typename T> // typename 可以替换class
函数声明或定义
```

**解释**

template  声明创建模板

typename  表明其后面的符号是一种数据类型，可以用class代替

T          通用的数据类型，名称可以替换通常为大写字母

```C++
//定义函数模板
template<typename T>
void f(T &a,T &b)
{
    T c;
    c =a;
    a= b;
    b=c;
}
///调用函数模板
//1、自动类型推导
int a,b;
f(a,b);
//2、显示指定类型推导
f<int>(a,b);
```

#### 1.2.2 函数模板注意事项

**注意事项：**

- 自动类型推导，必须推出一致的数据类型才可以使用
- 模板必须要确定出T的数据类型，才可以使用



【未完待续】







# STL

## 1 STL诞生

为了建立数据结构和算法的一套标准

## 2 STL基本概念

- STL(Standard Template Library ，标准模板库)
- STL从广义上分为：容器(container) 算法(algorithm) 迭代器(iterator)
- 容器和算法之间通过迭代器进行无缝衔接
- STL几乎所有的代码都采用了模板类或者模板函数

## 3 STL六大组件

六大组件:

1. 容器：各种数据结构，如vector，list，deque，set，map等，用来存放数据













## 4 数据结构

### 1.1 unordered_set 使用

unordered_set可以把它想象成一个集合，它提供了几个函数让我们可以增删查：
unordered_set::insert
unordered_set::find 会返回一个迭代器,这个迭代器指向和参数哈希值匹配的元素，如果没有匹配的元素，会返回这个容器的结束迭代器
unordered_set::erase

unorederd_set::end 返回结束的迭代器

这个unorder暗示着，这两个头文件中类的底层实现----Hash。 也是因为如此，你才可以在声明这些unordered模版类的时候，传入一个自定义的哈希函数，准确的说是哈希函数子（hash function object）。

## 5 字符串

### 5.1 strcmp(chars1,chars2)函数

针对char 数组的，两个字符串相等为0反之为-1；

## 

### 5.2 截取字符串的一部分

`string substr(int pos = 0,int n ) const;`

- **函数说明**

  参数1  pos是可缺省参数，默认为0，即：从字符串头开始读取。

  参数2  n表示取多少个字符

  该函数功能为：返回从pos开始的n个字符组成的字符串，**原字符串不被改变**。可以类比python中的切片

如要截取的是某个字符后面的一部分，可以先用`string find(char c);` 获得某个字符的 index然后用`substr`去截取所需的字符串。



### 5.3 字符串替换

**源字符串改变！**

```c++

void test1()
{   /*
    s.replace(pos, n, s1)     //用s1替换s中从pos开始（包括0）的n个字符的子串 
    */
    string s1 = "xcs is a good man";
    cout<<"s1:"<<s1<<endl;
    s1.replace(1,3,"xcsy");
    cout<<"s1_replace:"<<s1<<endl;
}
```

### 5.4 分割字符串

```c++
//通过使用strtok()函数实现
std::vector<std::string> split(const std::string &str,const std::string &pattern)
{
    //const char* convert to char*
    char * strc = new char[strlen(str.c_str())+1];
    strcpy(strc, str.c_str());
    std::vector<std::string> resultVec;
    char* tmpStr = strtok(strc, pattern.c_str());
    while (tmpStr != NULL)
    {
        resultVec.push_back(std::string(tmpStr));
        tmpStr = strtok(NULL, pattern.c_str());
    }
    
    delete[] strc;
    
    return resultVec;
};
//用STL里面的 findstr和substr实现
std::vector<std::string> splitWithStl(const std::string &str,const std::string &pattern)
{
    std::vector<std::string> resVec;

	if ("" == str)
    {
        return resVec;
    }
    //方便截取最后一段数据
    std::string strs = str + pattern;
    
    size_t pos = strs.find(pattern);
    size_t size = strs.size();

    while (pos != std::string::npos)
    {
        std::string x = strs.substr(0,pos);
        resVec.push_back(x);
        strs = strs.substr(pos+1,size);
        pos = strs.find(pattern);
    }
    
    return resVec;
}


```

### 5.5 字符串转数字

**用ato这个类**

```c++
string s1 = "12.001";
float d = atof(s1.c_str());
int a = atoi(s1.c_str()); //要转换成 int，double，long，long 分别用atoi,atof,atol,atoll
//ato这个类接收的是const char* char所以string 要用c_str()转换成char*
```

### 5.6 保留小数转换为字符串

```C++
#include <sstream>
auto formatDobleValue(double val, int fixed) {
    std::ostringstream oss;
    oss << std::setprecision(fixed) << val;
    return oss.str();
}

```



## 6 Vector

### 6.1  vector 排序

- vector中是可排序的类型如int,double,float等

```c++
// vector 排序
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
```

- vector中是自定义类型的排序

```c++
// vector中是自定义类型的排序
//自定义排序
struct student{
     char name[10];
     int score;
 };
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
```

### 6.2 vector删除元素

```c++
//vector删除元素
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
     /*2.和find 函数结合删除*/ //erase 删除元素
    vector<int>::iterator index = find(a.begin(),a.end(),30);
    if(index != a.end())
    {
        a.erase(index);
    }
    /* 3.遍历vector删除*/
    // for (vector<int>::iterator it = a.begin(); it != a.end(); it++){
    //     if(*it == 30)
    //     {
    //         it = a.erase(it);
    //     }
         
    // }
    for (vector<int>::iterator it = a.begin(); it != a.end(); it++){
         cout << *it << endl;
    }

}


```

### 6.3 两个vector合并

三种方式：

- inser方式
- merge方式
- 挨个遍历去做

```c++
// 合并vector
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
```

### 6.4 vector 求最大最小元素

```c++
vector<int> v:
//最大值：
int max =  *max_element(v.begin(),v.end());  
vector<int>::iterator max_it = max_element(v.begin(),v.end()); //则最大值为 *max_it 用这个可以用来求索引 
//最小值：
int min = *min_element(v.begin(),v.end());
```

### 6.5 vector 求最大最小元素的索引

```c++
int max_index = distance(a.begin(),max_element(a.begin(),a.end()));
int min_index = distance(a.begin(),min_element(a.begin(),a.end()));
```

## 7 Map

map和set是树形结构的关联式容器，使用平衡搜索树（红黑树）作为其底层结果，容器的元素是一个有序的序列。关联式容器是用来存储数据的，里面存储的是<key, value>结构的键值对，在数据检索时比序列式容器的效率更高。

**键值对**
键值对是用来表示具有一一对应关系的一种结构，该结构中一般包含两个成员变量key和value，key表示键值，value表示和key对应的信息。

**map O(logN)**
1.快速查找，通过key查找value。map支持下标访问符，即在[]中放入key，就可以找到与key对应的value。
2.附带作用，对key进行排序。在内部，map中的元素总是按照键值key进行比较排序的。

```c++
//map使用
void test12()
{   // map初始化
   map<string ,string > m{
       {"apple","苹果"},{"banana","香蕉"},{"orange","橘子"}
   };
   map<string ,string > m1;
   //map中插入元素
     //用pair的方式构造键值对
   m1.insert(pair<string,string>("peach","桃子"));
     //用make_pair的方式构造键值对
    m1.insert(make_pair<string,string>("he","他"));
      //用operator[] 插入元素   
    m1["she"] = "她";//类比python 的dict就是这个方式
    //map 遍历
    for(auto& e:m1)
    {
        cout<<e.first<<"--->"<<e.second<<endl;
    }
    //通过key访问value
    cout<<m1["peach"]<<endl;
    // map中的键值对key一定是唯一的，如果key存在将插入失败
	auto ret = m1.insert(make_pair("peach", "桃子"));
	if (ret.second)
		cout << "<peach, 桃子>不在map中, 已经插入" << endl;
	else
		cout << "键值为peach的元素已经存在：" << ret.first->first << "--->" <<
		ret.first->second << " 插入失败" << endl;
    // 删除key为"apple"的元素
	m.erase("apple");

}
```

**总结：**

1. map中的的元素是键值对。
2. map中的key是唯一的，并且不能修改。
3. 默认按照小于的方式对key进行比较。
4. map中的元素如果用迭代器去遍历，可以得到一个有序的序列。
5. map的底层为平衡搜索树(红黑树)，查找效率比较高。
6. 支持[]操作符，operator[]中实际进行插入查找。

### 7.1 map查找key

```c++
// 数据的查找（包括判定这个关键字是否在map中出现）
void test(vector<string,string> m1)
{

    /* 第一种：用count函数来判定关键字是否出现，其缺点是无法定位数据出现位置,由于map的特性，一对一的映射关系，就决定了count函数的返回值只有两个，要么是0，要么是1，出现的情况，当然是返回1了*/
    cout<<m1.count("peach")<<endl;
    cout<<m1.count("peache")<<endl;
    /* 第二种：用find函数来定位数据出现位置，它返回的一个迭代器，当数据出现时，它返回数据所在位置的迭代器，如果map中没有要查找的数据，它返回的迭代器等于end函数返回的迭代器，程序说明  */
    map<string,string>::iterator it,it1;
    it = m1.find("peach");
    it1 = m1.find("peache");
    if (it1 !=m1.end())
    {
        cout<<"find!"<<endl;
    }
    else
    {
        cout<<"not find"<<endl;
    }
}
```

### 7.2 map插入元素

```c++
//map中插入元素
void test(vector<string,string> &m1)
{
     //用pair的方式构造键值对
   m1.insert(pair<string,string>("peach","桃子"));
     //用make_pair的方式构造键值对
    m1.insert(make_pair<string,string>("he","他"));
      //用operator[] 插入元素   
    m1["she"] = "她";//类比python 的dict就是这个方式
}   
```

### 7.4 map清空和判空

清空map中的数据可以用clear()函数，判定map中是否有数据可以用empty()函数，它返回true则说明是空map

# 应用

## 1 [C++ 获取文件夹下的所有文件名](https://www.cnblogs.com/fnlingnzb-learner/p/6424563.html)

函数在台式机的 learningC++_vscode  test.cpp 下的 int getFiles(string,vector<string>);

## 2 输出控制小数点位数

在C++中输出要控制小数点的位数需要用到头文件iomanip中的setprecision(n)和setiosflags(ios::fixed)

其中setprecision(n)  设置浮点数的有效数字为n

setiosflags(ios::fixed) 设置浮点数以固定的小数位数显示

```c++
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double a=3.14159265358;                    
    cout<<a<<endl;                        //默认  输出为3.14159
    
    //加入setprecision(n)  设置浮点数有效数字 
    cout<<setprecision(3)<<a<<endl;        //将精度改为3（即有效数字三位） 输出3.14                        
    cout<<setprecision(10)<<a<<endl;    //将精度改为10  输出3.141592654 
    
    //加入setiosflags(ios::fixed)   设置浮点数以固定的小数位数显示
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<a<<endl;    
    //控制精度为小数位  setprecision(3)即保留小数点2位    输出3.14 
    cout<<a<<endl;                //fixed和setprecision的作用还在，依然显示3.14
            
    return 0;
}
```

## 3 C++实现多项式曲线拟合--polyfit

通过已知的(x,y)点来用最小二乘法拟合函数f(x)

```

```



## 4 最小二乘法(least squars)

```c++
// 最小二乘法
class LSquare
{
public:
    double *a;
    int n,ex;
    LSquare(vector<double> x,vector<double> y,int n,int ex)
    {   this->n = n;
        this->ex = ex;
        memset(a,0,sizeof(double)*ex);
        L_Sq(x,y,a,n,ex);
    } 
    double f(double x)
    {
        double res;
        res = 0;
        for (int i = 0; i < ex+1; i++)
        {           
            res += pow(x,i)* a[i];
            
        }
        return res;
    }  
    // 最小二乘法
// xy的次方和
    double RelateMutiXY(vector<double> x,vector<double> y,int n,int ex)
    {   double res;
        res = 0.0;  
            for (int j = 0; j < n; j++)
            {
                res += pow(x[j],ex) * y[j];
            }
        return res;
    }
    // x 的次方和
    double RelatePow(vector<double> x,int n,int ex)
    {   double res;
        res = 0.0;
        for (int i = 0; i < n; i++)
        {
            res += pow(x[i],ex);
        }

        return res;
        
    }
    void CalEquation(double **AB,double a[],int ex)
    {
    for (int k = 0; k < ex+1; k++)
    {    
        for (int i = 0; i < ex+1; i++)
        {
            if(i!=k)
            {
                double p=0;
                if (AB[k][k]!=0)
                {
                    p = AB[i][k]*1.0/ AB[k][k];
                }
                for (int j = k; j < ex+2; j++)
                {
                    AB[i][j] -= AB[k][j] * p;
                }

            }
        }
        
    }
    for (int i = 0; i < ex+1; i++)
    {   
        a[i] = AB[i][ex+1]*1.0/AB[i][i];
        

    }
    
    
    }

    void L_Sq(vector<double> x,vector<double> y,double a[],int n,int ex)
    {   // 参数ex 表示 拟合的多项式的最高次幂
        // double A[ex+1][ex+1];  
        // doubel B[ex+1][1];
        //double AB[ex+1][ex+2]; // 这里参考增广矩阵
    //  构造矩阵相乘 A*X = Y (这里A，X，Y是最后求导得到的 矩阵)
    // 这里就是 A*a = B  求解a,a为系数矩阵
        //构造矩阵A
        double **AB;
        AB = new double*[ex+1];

        for(int i=0;i<ex+1;i++)
        {   AB[i] = new double[ex+2];
            for (int j = 0; j < ex+1; j++)
            {   //cout<<RelatePow(x,n,i+j)<<endl;
                AB[i][j] = RelatePow(x,n,i+j);
            }

            AB[i][ex+1] = RelateMutiXY(x,y,n,i);
        }
        AB[0][0] = n;
        
        CalEquation(AB,a,ex); // 解A*X = Y (A|Y)--初等变换->(E|X)

    }

};

void test13()
{
    vector<double> x{0,0.25,0,5,0.75};
    vector<double> y{1,1.283,1.649,2.212,2.178};
    LSquare ls(x,y,5,2);
    for (int i = 0; i < 3; i++)
    {
        cout<<ls.a[i]<<endl;
       
    }
     cout<<ls.f(0.25)<<endl;
    
}
```



# C++调用Python

## 1 基本流程



## 2 使用中遇到的问题

### 2.1 导入模块时 模块名为test会报错

```c++
PyObject *pModule = PyImport_ImportModule("test")  // 导入模块名会报错，我也不知道为啥
```

