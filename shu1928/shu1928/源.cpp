#include<string>
#include<algorithm>
#include<iostream>
#include<cctype>

using namespace std;
int main()
{
	string line;
	while (cin>>line)
	{
		for (auto i = line.begin(); i != line.end(); i++)
		{
			*i = tolower(*i);//所有字符都变小写
		}
		int pos = line.find("bob");//调用find成员函数
		if (pos != string::npos)
		    cout << pos << endl;
		else
		{
			cout << -1 << endl;
		}
	}
}