#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

//kuangbin�����ĸ�˹��Ԫģ��
#define eps 1e-9
const int MAXN=220;
double a[MAXN][MAXN],x[MAXN];//���̵����ߵľ����͵�ʽ�ұߵ�ֵ������֮��x���ľ��ǽ���
int equ,var;//��������δ֪������
/*
*����0��ʾ�޽⣬1��ʾ�н�
*/
int Gauss()
{
    int i,j,k,col,max_r;
    for(k=0,col=0;k<equ&&col<var;k++,col++)
    {
        max_r=k;
        for(i=k+1;i<equ;i++)
            if(fabs(a[i][col])>fabs(a[max_r][col])) max_r=i;
        if(fabs(a[max_r][col])<eps) return 0;
        if(k!=max_r)
        {
            for(j=col;j<var;j++)
                swap(a[k][j],a[max_r][j]);
            swap(x[k],x[max_r]);
        }
        x[k]/=a[k][col];
        for(j=col+1;j<var;j++)
            a[k][j]/=a[k][col];
        a[k][col]=1;
        for(i=0;i<equ;i++)
            if(i!=k)
            {
                x[i]-=x[k]*a[i][k];
                for(j=col+1;j<var;j++)
                    a[i][j]-=a[k][j]*a[i][col];
                a[i][col]=0;
            }
    }
    return 1;
}

int n;
int max_var;
int now_max_var;
int can_shu,last_can_shu;
bool need_const;
double b[MAXN],c[MAXN];
bool vis[MAXN];

bool Check(bool need_const)
{
    memset(c,0,sizeof(c));
    for(int i=0;i<now_max_var;i++)
        c[i]=b[i];
    if(need_const)
    {
        for(int i=now_max_var;i<n;i++)
        {
            for(int k=0,j=max_var;k<var-1;k++,j--)
            {
                while(!vis[j]) j--;
                c[i]+=x[k]*c[i-j];
            }
            c[i]+=x[var-1];
            if(c[i]!=b[i]) return 0;
        }
        return 1;
    }
    else
    {
        for(int i=now_max_var;i<n;i++)
        {
            for(int k=0,j=max_var;k<var;k++,j--)
            {
                while(!vis[j]) j--;
                c[i]+=x[k]*c[i-j];
            }
            if(c[i]!=b[i]) return 0;
        }
        return 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout<<"��������������ǰ��������ĳһ�����Թ�ϵ��"<<endl;
    cout<<"�����������õ�����n��";
    cin>>n;
    cout<<"���������������õ���ai��";
    for(int i=0;i<n;i++)
        cin>>b[i];
    cout<<"���������Ʒ����Ƿ���Ҫ���㳣�����Ҫ��1������Ҫ��0:";
    cin>>need_const;
    int cas=1;
    if(need_const)
    {
        cout<<"��������Ҫ���������������� "<<(n-1)/2<<" �����볣�������"<<endl;
        cout<<"An = ";
        for(int i=1;i<=(n-1)/2;i++)
            cout<<"x"<<i<<"*An-"<<i<<" + ";
        cout<<"d"<<endl;
        cout<<"�����У�"<<endl<<endl;
        max_var=(n-1)/2;
        for(int i=1;i<(1<<max_var);i++)
        {
            memset(vis,0,sizeof(vis));
            for(int j=0;j<max_var;j++)
                if( i & (1<<j) ) vis[j+1]=1;
            var=0;
            for(int j=1;j<=max_var;j++)
                if(vis[j]) var++;
            var++;
            equ=var;
            now_max_var=max_var;
            while(now_max_var!=0 && !vis[now_max_var]) now_max_var--;
            for(int p=0;p<equ;p++)
            {
                last_can_shu=can_shu=now_max_var;
                for(int q=0;q<var+1;q++)
                {
                    if(q==var-1) {a[p][q]=1;continue;}
                    if(q==var) {x[p]=b[now_max_var+p];continue;}
                    a[p][q]=b[last_can_shu-can_shu+p];
                    last_can_shu=can_shu;
                    can_shu--;
                    while(can_shu!=0 && !vis[can_shu]) can_shu--;
                }
            }
            if(Gauss() && Check(need_const))
            {
                cout<<"���������ĵ� "<<cas++<<" �����Ե���ʽΪ��"<<endl;
                cout<<"An = ";
                for(int i=0,j=max_var;i<var-1;i++,j--)
                {
                    while(!vis[j]) j--;
                    cout<<x[i]<<"*An-"<<j<<" + ";
                }
                cout<<x[var-1]<<endl;
                for(int i=0;i<now_max_var;i++)
                    cout<<"A"<<i<<"="<<b[i]<<((i==now_max_var-1)?"\n":",");
                cout<<endl;
            }
        }
    }
    else
    {
        cout<<"��������Ҫ���������������� "<<n/2<<" ����������"<<endl;
        cout<<"An = ";
        for(int i=1;i<=n/2;i++)
            cout<<"x"<<i<<"*An-"<<i<<((i==n/2)?"\n":" + ");
        cout<<"�����У�"<<endl<<endl;
        max_var=n/2;
        for(int i=1;i<(1<<max_var);i++)
        {
            memset(vis,0,sizeof(vis));
            for(int j=0;j<max_var;j++)
                if( i & (1<<j) ) vis[j+1]=1;
            var=0;
            for(int j=1;j<=max_var;j++)
                if(vis[j]) var++;
            equ=var;
            now_max_var=max_var;
            while(now_max_var!=0 && !vis[now_max_var]) now_max_var--;
            for(int p=0;p<equ;p++)
            {
                last_can_shu=can_shu=now_max_var;
                for(int q=0;q<var+1;q++)
                {
                    if(q==var) {x[p]=b[now_max_var+p];continue;}
                    a[p][q]=b[last_can_shu-can_shu+p];
                    last_can_shu=can_shu;
                    can_shu--;
                    while(can_shu!=0 && !vis[can_shu]) can_shu--;
                }
            }
            if(Gauss() && Check(need_const))
            {
                cout<<"���������ĵ� "<<cas++<<" �����Ե���ʽΪ��"<<endl;
                cout<<"An = ";
                for(int i=0,j=max_var;i<var;i++,j--)
                {
                    while(!vis[j]) j--;
                    cout<<x[i]<<"*An-"<<j<<((i==var-1)?"\n":" + ");
                }
                for(int i=0;i<now_max_var;i++)
                    cout<<"A"<<i<<"="<<b[i]<<((i==now_max_var-1)?"\n":",");
                cout<<endl;
            }
        }
    }
}

