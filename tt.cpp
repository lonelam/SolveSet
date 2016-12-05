#include<bits/stdc++.h>
using namespace std;



int main()
{
     int m,n;
     int i,j,t,count=0;
     cout << "ÇëÊäÈëline col£º" <<endl;
     cin >> m >> n ;
     int (*p)[n];
     int arr[m][n];
     cout <<"ÇëÊäÈë¾ØÕó£º"<<endl;
     for(i=0;i<m;i++)
      for(j=0;j<n;j++)
      cin >> arr[i][j];

      for(int i = 0; i < m; i++)
      {
      	for(int j = n - 1; j>= 0; j--)
      	{
      		cout<< arr[i][j]<<" ";
      	}
      	cout<<endl;
      }
    system("pause");
    return 0;
}
