#include<iostream>
#include<memory>
#include<cstring>
using namespace std;

int main()
{
	int x = 1;
	char * poor;
	while(true)
	{
		poor = new char[x];
		memset(poor,-1,sizeof(char) * x);
		cout<<x <<" Bytes memory allocated"<<endl;
		system("pause");
		delete poor;
		x<<=1;
	}
} 
