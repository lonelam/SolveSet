#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
double height[10001];

double solve(int left,int right,int L)
{
    double ans,sum = 0;
    int alti_cnt = 0;
    double alti_land= height[left];
    for(int i=left;i<left+L;i++)
    {
        if(height[i]<alti_land)
        {
            alti_land = height[i];
            alti_cnt = 1;
        }
        else if(height[i]==alti_land)
        {
            alti_cnt++;
        }
        sum+=(height[i]+height[i+1])/2;

    }
    if(height[left+L]<alti_land)
        {
            alti_land = height[left+L];
            alti_cnt = 1;
        }
        else if(height[left+L]==alti_land)
        {
            alti_cnt++;
        }
    ans = sum - alti_land * L;
    for(int i=left+1, j = left+L+1;j<=right;i++,j++)
    {
        if(height[i-1]==alti_land&&alti_cnt-- == 1)
        {
            alti_land = height[i];
            for(int k=i;k<j;k++)
            {
                if(height[k]<alti_land)
                {
                    alti_land = height[k];
                    alti_cnt = 1;
                }
                else if(height[k]==alti_land)
                {
                    alti_cnt ++;
                }
            }
        }
        if(height[j]<alti_land)
        {
            alti_land = height[j];
            alti_cnt = 1;
        }
        else if(height[j] == alti_land)
        {
            alti_cnt ++;
        }
        sum -= (height[i-1]+height[i])/2;
        sum += (height[j-1]+height[j])/2;
      //  cout<<"**Debug cur sum:"<<sum<<"  cur ans:"<<ans<<" cur alti_land = "<<alti_land<<endl;
        ans = min(ans,sum-alti_land* L);
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(height,0,sizeof(height));
        int n,l;
        double y;
        int x;
        cin>>n>>l;
        int prev,ll,rr;
        cin>>x>>y;
        prev = x;
        ll = x;
        height[x] = y;
        while(--n)
        {
            cin>>x>>y;
            double tangent = (y - height[prev])/(x-prev);
            for(int i=prev+1;i<=x;i++)
            {
                height[i] = height[i-1] + tangent;
                cout<<"**Debug : set height["<<i<<"] = "<<height[i]<<endl;
            }
            prev = x;
        }
        rr = x;
        cout.setf(ios::fixed);
        cout.precision(4);
        cout<<solve(ll,rr,l)<<endl;
    }
}

/**************************************************************
    Problem: 2034
    User: 15123005
    Language: C++
    Result: Wrong Answer
****************************************************************/
