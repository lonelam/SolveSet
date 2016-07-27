#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		string ip;
	//	int cur = 0, step = 0;
		if (s.size() < 4)
		{
			return result;
		}
		dfs(s, result, ip, 1,0, 0);
		return result;
	}
	void dfs(const string & s, vector<string> & result, string ip, int cur, int start,int dot)
	{
		if (cur == s.size())
		{
			if (dot != 3)
			{
				return;
			}
			if (stoi(s.substr(start, cur - start)) <= 255)
			{
				ip.append(s.substr(start, cur - start));
				result.push_back(ip);
				return;
			}
			return;
		}
		if (s[start] == '0')
		{
			if (dot < 3)
			{
				dfs(s, result, ip + "0.", cur + 1, cur, dot + 1);
				
			}
			return;
		}
		if (dot < 3)
		{
			if(cur-start<3 ||stoi(s.substr(start,cur-start))<=255)
			dfs(s, result, ip + s.substr(start, cur - start) + '.', cur + 1, cur, dot + 1);
		}
		if (cur - start < 3)
		{
			dfs(s, result, ip, cur + 1, start, dot);
		}
	}
};