
/*

4 4
1255 197 31 1 7997
7997 1255 197 1 50959
50959
7997 1255 1 324725
324725 50959 7997 1 2069239

*/
/*
*Gauss.cpp
*功能：列选主元消元法
*/
#include<stdio.h>
#include"Gass.h"

//高斯消元法（列选主元）
void Gauss (double a[][MAXNUM],int n)
{
    int i,j;
    SelectColE(a,n);   //列选主元并消元成上三角
    //回代求解
    printf("上三角的结果\n");
    printM(a,3);
    for(i=n;i>=1;i--)
    {
        for(j=i+1;j<=n;j++)
            a[i][n+1]-=a[i][j]*a[j][n+1];
        a[i][n+1]/=a[i][i];
    }
    return ;
}
//选择列主元并进行消元
void SelectColE(double a[][MAXNUM],int n)
{
    int i,j,k,maxRowE;
    double temp; //用于记录消元时的因数
    for(j=1;j<=n;j++)
    {
        maxRowE=j;
        for(i=j;i<=n;i++)
            if(fabs(a[i][j])>fabs(a[maxRowE][j]))
                maxRowE = i;
        if(maxRowE!=j)
            swapRow(a,j,maxRowE,n);   //与最大主元所在行交换
        //消元
        for(i=j+1;i<=n;i++)
        {
            temp =a[i][j]/a[j][j];
            for(k=j;k<=n+1;k++)
                a[i][k]-=a[j][k]*temp;
        }
        printf("第%d列消元后：\n",j);
        printM(a,3);
    }
    return;
}
void swapRow(double a[][MAXNUM],int m,int maxRowE,int n)
{
    int k;
    double temp;
    for(k=m;k<=n+1;k++)
    {
        temp = a[m][k];
        a[m][k] = a[maxRowE][k];
        a[maxRowE][k] = temp;
    }
    return ;
}

//测试函数
int main()
{
    double a[4][MAXNUM];

    int i,n,j;

    a[1][1] = 0.001; a[1][2]=2.000;a[1][3]=3.000;a[1][4]=1.000;
    a[2][1] = -1.000;a[2][2]=3.712;a[2][3]=4.623;a[2][4]=2.000;
    a[3][1] = -2.000;a[3][2]=1.070;a[3][3]=5.643;a[3][4]=3.000;
    Gauss (a,3);
    for(i=1;i<=3;i++)
        printf("X%d=%f\n",i,a[i][4]);
    return 0;
}
//输出矩阵
void printM(double a[][MAXNUM], int n)
{
   int i,j;
   for(i=1;i<=n;i++)
    {
        for(j=1;j<=n+1;j++)
        {
            printf("%f ,",a[i][j]);
        }
        printf("\n");
    }
}
