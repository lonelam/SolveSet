#include<iostream>
#include<algorithm>
using namespace std;

int h[6000]={0,1};

int main()
{
	int e,s,w,q;
	e=s=w=q=1;
	for(int i=2;i<=5200;i++)
	{
		h[i]=min(min(h[e]*2,h[s]*3),min(h[w]*5,h[q]*7));
		if(h[i]/h[e]==2)
			e++;
		if(h[i]/h[s]==3)
			s++;
		if(h[i]/h[w]==5)
			w++;
		if(h[i]/h[q]==7)
			q++;
	}
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int l=lower_bound(h,h+5200,n)-h;
		cout<<h[l]<<endl;
	}
	return 0;
}

