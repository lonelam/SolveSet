#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solutionme {
public:
	int trap(vector<int>& height) {
		int len = height.size();
		int lh = 0, rh = 0;
		vector<int> lhs(len, 0);
		vector<int> rhs(len, 0);
		for (int i = 0; i < len; i++)
		{
			lhs[i] = lh;
			lh = max(lh, height[i]);
		}
		for (int i = len - 1; i >= 0; i--)
		{
			rhs[i] = rh;
			rh = max(rh, height[i]);
		}
		int result = 0;
		for (int i = 0; i < len; i++)
		{
			result += max(0, min(lhs[i], rhs[i]) - height[i]);
		}
		return result;
	}
};


class Solutionbetter {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			if (height[i] > height[max])
			{
				max = i;
			}
		}
		int water = 0;
		for (int i = 0, peak = 0; i < max; i++)
		{
			if (height[i] > peak)
			{
				peak = height[i];
			}
			else
			{
				water += peak - height[i];
			}
		}
		for (int i = n - 1,top = 0; i > max; i--)
		{
			if (height[i] > top)
			{
				top = height[i];
			}
			else
			{
				water += top - height[i];
			}
		}
		return water;
		
	}
};

class Solution {
public:
	int trap(vector<int>& height) {
		int len = height.size();
		stack<pair<int, int>> s;
		int water = 0;
		for (int i = 0; i < len; i++)
		{
			int h = 0;
			while (!s.empty())
			{
				int bar = s.top().first;
				int pos = s.top().second;
				water += (min(bar, height[i]) - h) * (i - pos - 1);
				h = bar;
				if (height[i] < bar)
				{
					break;
				}
				else
				{
					s.pop();
				}
			}
			s.push(make_pair(height[i], i));
		}
		return water;
	}
};