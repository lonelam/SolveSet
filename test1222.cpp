#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int gcd_extend(int a,int b,int &x,int &y)//欧几里得算法扩展形式
{
    if(!b){
        x=1;
        y=0;
    return a;}
    int g=gcd_extend(b,a%b,x,y);
    int t=x-(a/b)*y;
    x=y;
    y=t;
    return g;
}
/*
void solver(int a,int b,int n)//解方程
{
    int x,y;
    int d=gcd_extend(a,n,x,y);
    if(b%d==0)
    {
        int x1=x*(b/d)%n;
        for(int i=0;i<d;i++)
        cout<<(x1+i*(n/d))%n<<endl;
    }
    else
    cout<<"无解"<<endl;
}
*/
void solver(int a,int b,int n)//解方程
{
    int x,y;
    int d=gcd_extend(a,n,x,y);
    if(b%d==0)
    {
        int x1=x*(b/d)%n;
        for(int i=0;i<d;i++)
          {
              int t=(x1+i*(n/d))%n;//由于负数无意义，那么负数就要判定在输出
              if(t<0)
              {
                  t=(t+n)%n;
              }
              cout<<t<<endl;
          }
    }
    else
    cout<<"无解"<<endl;
}
int main()
{
    int a,b,n;
    while(cin>>a>>b>>n)
    {
        solver(a,b,n);
    }
    return 0;
}

/*
这是模线性方程的模版，自己写的，加油

测试数据：
14 30 100
10 20 30
10 35 62

95 45
2 5 8 11 14 17 20 23 26 29
无解
*/
