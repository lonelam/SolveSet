#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

// thanks to pyf

int tar[100010];
int dp[100010];
// dp[i] = max(dp[i-1]+tar[i],dp[i]);



int main()
{
    ios::sync_with_stdio(false);
	int T;
	cin >> T;
	int a = 0;
	while(T--)
	{
	//	char x;
	//	int a=0;
		int n;
		//memset(dp,0,sizeof(dp));
		//memset(tar,0,sizeof(tar));
		cin >> n;
	//	while(scanf("%d%c",&tar[a++],&x)==2&&x!='\n');
	//	cout << "&&" << endl;
		int anss,anse;
		int Max=;
		anss=anse=1;
		int temp=1;
	//	for(int i=1;i<=n;i++)

		for(int i=1;i<=n;i++)
		{
		//	scanf("%d",&tar[i]);
			cin >> tar[i];
			if(dp[i-1]>=0)
			{
				dp[i]=dp[i-1]+tar[i];
				if(dp[i] > Max)
				{
					Max = dp[i];
					anss = temp;
					anse = i;
				}
			}
			else
			{
				dp[i]=tar[i];
				temp = i ;
				if(dp[i] > Max)
				{
					anss = temp;
					anse = i ;
				}
			}
		}
//		int Max=dp[1];
//		int anss;
//		int anse;
//		for(int i=2;i<=n;i++)
//		{
//			if(dp[i]>Max)
//			{
//				Max=dp[i];
//				anse=i;
//			}
//		}
//		int res=0;
//		for(int i=anse;i>=1;i--)
//		{
//			res+=tar[i];
//			if(Max==res)
//			{
//				anss=i;
//				break;
//			}
//
//		}
		cout << "Case "<<++a<<":"<<endl;
		cout << Max <<" "<< anss << " " << anse << endl;
//		dp[0]=tar[0];
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=i;i<=n;j++)
//			{
//				dp[i]=max(dp[i],dp[i-1]+tar[j]);
//			}
//		}
//		cout << dp[n] << endl;
	}
	return 0;
}
