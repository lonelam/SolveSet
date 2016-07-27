#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	vector<string> addOperators(string num, int target) {
		vector<string> result;
		string path;
		dfs(num, path, result, target, 0, 0, 0, 0);
		return result;
	}

	void dfs(string & num, string & path, vector<string> & result, int target, int cur,int start, long long upper, long long lower)
	{
		if (start == num.size())
		{
			
			if (target == lower + upper)
			{
				result.push_back(path);
			}
			return;
		}
		int bk = path.size();
	
		if (cur == num.size())
		{
			return;
		}
		if (start == 0)
		{
			if (num[start] == '0')
			{
				path += '0';
				dfs(num, path, result, target, cur + 1, start + 1, 0, 0);
				path.pop_back();
			}
			else
			{
				path.append(num.substr(start, cur - start + 1));
				
				dfs(num, path, result, target, cur + 1, cur + 1, stoll(num.substr(start, cur - start + 1)), lower);
				path.erase(path.begin() + bk, path.end());
				dfs(num, path, result, target, cur + 1, start, upper, lower);
			}
			return;
		}

		if (num[start] == '0')
		{

			path += "+0";
			dfs(num, path, result, target, cur + 1, start + 1, 0, lower + upper);
			path.erase(path.begin() + bk, path.end());
			path += "-0";
			dfs(num, path, result, target, cur + 1, start + 1, 0, lower + upper);
			path.erase(path.begin() + bk, path.end());
			path += "*0";
			dfs(num, path, result, target, cur + 1, start + 1, 0, lower);
			path.erase(path.begin() + bk, path.end());
			return;
		}
		path += '+';
		path += num.substr(start, cur - start + 1);
		dfs(num, path, result, target, cur + 1, cur + 1, stoll(num.substr(start, cur - start + 1)), upper + lower);
		path.erase(path.begin() + bk, path.end());
		path += '-';
		path += num.substr(start, cur - start + 1);
		dfs(num, path, result, target, cur + 1, cur + 1, -stoll(num.substr(start, cur - start + 1)), upper + lower);
		path.erase(path.begin() + bk, path.end());
		path += '*';
		path += num.substr(start, cur - start + 1);
		dfs(num, path, result, target, cur + 1, cur + 1, upper *stoll(num.substr(start, cur - start + 1)), lower);
		path.erase(path.begin() + bk, path.end());
		dfs(num, path, result, target, cur + 1, start, upper, lower);
	}
};





int main()
{
	Solution slt;
	auto ans = slt.addOperators("3456237490", 9191);
	for (auto x : ans)
	{
		cout << x << endl;
	}
	system("pause");
}
