
/*

4 4
1255 197 31 1 7997
7997 1255 197 1 50959
50959
7997 1255 1 324725
324725 50959 7997 1 2069239

*/
/**
高斯消元求解线性方程组.
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

///高斯消元模板
const double eps = 1e-12;
const int Max_M = 15;       ///m个方程,n个变量
const int Max_N = 15;
int m, n;
double Aug[Max_M][Max_N+1]; ///增广矩阵
bool free_x[Max_N];         ///判断是否是不确定的变元
double x[Max_N];            ///解集

int sign(double x){ return (x>eps) - (x<-eps);}

/**
返回值:
-1 无解
0 有且仅有一个解
>=1 有多个解,根据free_x判断哪些是不确定的解
*/
int Gauss()
{
    int i,j;
    int row,col,max_r;
    for(row=0,col=0; row<m&&col<n; row++,col++)
    {
        max_r = row;
        for(i = row+1; i < m; i++)  ///找到当前列所有行中的最大值(做除法时减小误差)
        {
            if(sign(fabs(Aug[i][col])-fabs(Aug[max_r][col]))>0)
                max_r = i;
        }
        if(max_r != row)            ///将该行与当前行交换
        {
            for(j = row; j < n+1; j++)
                swap(Aug[max_r][j],Aug[row][j]);
        }
        if(sign(Aug[row][col])==0)  ///当前列row行以下全为0(包括row行)
        {
            row--;
            continue;
        }
        for(i = row+1; i < m; i++)
        {
            if(sign(Aug[i][col])==0)
                continue;
            double ta = Aug[i][col]/Aug[row][col];
            for(j = col; j < n+1; j++)
                Aug[i][j] -= Aug[row][j]*ta;
        }
    }
    for(i = row; i < m; i++)    ///col=n存在0...0,a的情况,无解
    {
        if(sign(Aug[i][col]))
            return -1;
    }
    if(row < n)     ///存在0...0,0的情况,有多个解,自由变元个数为n-row个
    {
        for(i = row-1; i >=0; i--)
        {
            int free_num = 0;   ///自由变元的个数
            int free_index;     ///自由变元的序号
            for(j = 0; j < n; j++)
            {
                if(sign(Aug[i][j])!=0 && free_x[j])
                    free_num++,free_index=j;
            }
            if(free_num > 1) continue;  ///该行中的不确定的变元的个数超过1个,无法求解,它们仍然为不确定的变元
            ///只有一个不确定的变元free_index,可以求解出该变元,且该变元是确定的
            double tmp = Aug[i][n];
            for(j = 0; j < n; j++)
            {
                if(sign(Aug[i][j])!=0 && j!=free_index)
                    tmp -= Aug[i][j]*x[j];
            }
            x[free_index] = tmp/Aug[i][free_index];
            free_x[free_index] = false;
        }
        return n-row;
    }
    ///有且仅有一个解,严格的上三角矩阵(n==m)
    for(i = n-1; i >= 0; i--)
    {
        double tmp = Aug[i][n];
        for(j = i+1; j < n; j++)
            if(sign(Aug[i][j])!=0)
                tmp -= Aug[i][j]*x[j];
        x[i] = tmp/Aug[i][i];
    }
    return 0;
}
///模板结束

int main()
{
    int i,j;
    int t;
    double a[12][12];
    scanf("%d",&t);
    while(t--)
    {
        memset(Aug,0.0,sizeof(Aug));
        memset(x,0.0,sizeof(x));
        memset(free_x,1,sizeof(free_x));    ///都是不确定的变元
        for(i = 0; i < 12; i++)
            for(j = 0; j < 12; j++)
                scanf("%lf",&a[i][j]);
        double sum=0;
        for(int i=0;i<11;i++)
            sum+=a[11][i]*a[11][i];
        for(int i=0;i<11;i++)
        {
              for(int j=0;j<11;j++)
              {
                  Aug[i][j]=2*(a[i][j]-a[11][j]);
                  Aug[i][11]+=a[i][j]*a[i][j];
              }
              Aug[i][11]+=-a[i][11]*a[i][11]+a[11][11]*a[11][11]-sum;
        }
        m = n = 11;
        Gauss();
        for(int i = 0; i < n; i++)
        {
            printf("%.2lf",x[i]);
            printf("%c",i==n-1?'\n':' ');
        }
    }
    return 0;
}
