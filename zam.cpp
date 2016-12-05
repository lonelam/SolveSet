#include<iostream>
using namespace std;
double p(double y,double b0,double b1=0,double b2=0,double b3=0);
int main()
{
    double sum,a0,a1,a2,a3,x;
    cout<<"请输入a0+a1*x+a2*x*x+a3*x*x*x中的x,a0,a1,a2,a3:";
    cin>>x>>a0>>a1>>a2>>a3;
    sum=p(x,a0,a1,a2);
    cout <<"多项式的和为："<<sum<<endl;
//    system("pause");
    return 0;
}
double p(double y,double b0,double b1,double b2,double b3)
{
    return b0+b1*y+b2*y*y+b3*y*y*y;
}

