#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		auto cur = digits.rbegin();
		while (*cur == 9 && cur != digits.rend())
		{
			*cur = 0;
			cur++;

		}
		if (cur == digits.rend())
		{
			digits.insert(digits.begin(), 1);
		}
		else
		{
			(*cur)++;
		}
		return digits;
	}
};