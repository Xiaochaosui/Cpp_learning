#include <iostream>
#include <vector>
#include <math.h>
#include<algorithm>
#include <string.h>
#include <cstring>
using namespace std;
// 最小二乘法
class LSquare
{
public:
    double *a;
    int n,ex;
    // 构造函数
    LSquare(vector<double> x,vector<double> y,int n,int ex)
    {   this->n = n;
        this->ex = ex;
        a = new double[ex];
        memset(a,0,sizeof(double)*ex); // 来自于string.h
        L_Sq(x,y,a,n,ex);
    } 
    // 拟合的多项式y = a0 *x^0 + a1 *x^1 + a2 *x^2.... 求值
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
    // 解A*X = Y (A|Y)--初等变换->(E|X)
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
    // 构造增广矩阵运算
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
void test()
{
    
    vector<double> x{0,0.25,0,5,0.75};
    vector<double> y{1,1.283,1.649,2.212,2.178};
    LSquare ls = LSquare(x,y,x.size(),3);
    for (int i = 0; i < 5; i++)
    {
        cout<<"系数："<<ls.a[i]<<endl;
       
    }

    
    cout<<ls.f(0)<<endl;
    

}
int main()
{   system("chcp 65001");
    test();
    system("pause");
    return 0;
}