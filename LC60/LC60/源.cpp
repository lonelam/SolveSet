#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		string s(n, '0');
		string result;
		for (int i = 1; i <= n; i++)
		{
			s[i] += i;
		}
		return kth_permutation(s, k);
	}
private:
	int factorial(int n)
	{
		int result = 1;
		for (int i = 1; i <= n; i++)
		{
			result *= i;
		}
		return result;
	}
	template<typename Sequence>
	Sequence kth_permutation(const Sequence & seq, int k)
	{
		const int n = seq.size();
		Sequence S(seq);
		Sequence result;

		int base = factorial(n - 1);
		--k;

		for (int i = n - 1; i > 0; k %= base, base /= i, --i)
		{
			auto a = next(S.begin(), k / base);
			result.push_back(*a);
			S.erase(a);
		}
		result.push_back(S[0]);
		return result;
	}
};