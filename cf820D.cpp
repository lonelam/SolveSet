/*
 * hihocoder 1388 Periodic Signal
 *
 * 把式子变形一下就是求Ai*Bi+k求和的最大值，想到用FFT来求
 * 会因为精度问题不能过，这是找出最小的那个k，然后重新算即可。
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000+10;
const double PI = acos(-1.0);

struct Complex
{
    double r,i;
    Complex(double _r=0,double _i=0):r(_r),i(_i){}
    Complex operator + (const Complex& rhs)
    {
        return Complex(r+rhs.r,i+rhs.i);
    }
    Complex operator - (const Complex& rhs)
    {
        return Complex(r-rhs.r,i-rhs.i);
    }
    Complex operator * (const Complex &rhs)
    {
        return Complex(r*rhs.r - i*rhs.i,i*rhs.r + r*rhs.i);
    }
};
/*
 * 进行FFT和IFFT前的反转变换。
 * 位置i和 （i二进制反转后位置）互换
 * len必须取2的幂
 */
void Rader(Complex F[],int len)
{
    int j = len >> 1;
    for(int i = 1;i < len - 1;++i)
    {
        if(i < j) swap(F[i],F[j]);  // reverse
        int k = len>>1;
        while(j>=k)
        {
            j -= k;
            k >>= 1;
        }
        if(j < k) j += k;
    }
}
/*
 * 做FFT
 * len必须为2^k形式，
 * on==1时是DFT，on==-1时是IDFT
 */
void FFT(Complex F[],int len,int t)
{
    Rader(F,len);
    for(int h=2;h<=len;h<<=1)
    {
        Complex wn(cos(-t*2*PI/h),sin(-t*2*PI/h));
        for(int j=0;j<len;j+=h)
        {
            Complex E(1,0); //旋转因子
            for(int k=j;k<j+h/2;++k)
            {
                Complex u = F[k];
                Complex v = E*F[k+h/2];
                F[k] = u+v;
                F[k+h/2] = u-v;
                E=E*wn;
            }
        }
    }
    if(t==-1)   //IDFT
        for(int i=0;i<len;++i)
            F[i].r/=len;
}
void Conv(Complex a[],Complex b[],int len) //求卷积
{
    FFT(a,len,1);
    FFT(b,len,1);
    for(int i=0;i<len;++i) a[i] = a[i]*b[i];
    FFT(a,len,-1);
}
Complex va[MAXN],vb[MAXN];
int A[MAXN],B[MAXN],n,len;
int AA[MAXN];
void init()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&A[i]);
    for(int i=0;i<n;i++) scanf("%d",&B[i]);
    for(int i=n;i<2*n;i++) B[i]=B[i-n];
    for(int i=0;i<n;i++) AA[i]=A[n-i-1];
    len=1;
    while(len<2*n) len<<=1;
    for(int i=0;i<n;i++) va[i]=Complex(AA[i],0);
    for(int i=n;i<len;i++) va[i]=Complex(0,0);
    for(int i=0;i<2*n;i++) vb[i]=Complex(B[i],0);
    for(int i=2*n;i<len;i++) vb[i]=Complex(0,0);
}
void solve()
{
    init();
    Conv(va,vb,len);
    double ans=0;
    int k;
    for(int i=n-1;i<=2*n-2;i++)
    {
        if(va[i].r>ans)
        {
            ans=va[i].r;
            k=i;
        }
    }
    k-=n-1;
    long long a=0,b=0,ab=0;
    for(int i=0;i<n;i++) a+=(long long)A[i]*A[i];
    for(int i=0;i<n;i++) b+=(long long)B[i]*B[i];
    for(int i=0;i<n;i++) ab+=(long long)A[i]*B[i+k];
    long long res=a+b-2*ab;
    printf("%lld\n",res);
}
int main()
{
    int T;
    int n;
    scanf("%d",&T);
    while(T--)
    {
        solve();
    }
    return 0;
}
