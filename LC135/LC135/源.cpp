class Solution1 {
public:
	int candy(vector<int>& ratings) {
		const int n = ratings.size();
		vector<int> increment(n);

		increment[0] = 1;
		for (int i = 1; i < n; i++)
		{
			if (ratings[i] > ratings[i - 1])
			{
				increment[i] = increment[i - 1] + 1;
			}
			else
			{
				increment[i] = 1;
			}
		}
		int sum = increment[n - 1];
		for (int i = n - 1; i > 0; i--)
		{
			if (ratings[i - 1] > ratings[i])
			{
				increment[i - 1] = max(increment[i - 1], increment[i] + 1);
				sum += increment[i - 1];
			}
		}
		return sum;
	}
};

class Solution {
public:
	int candy(vector<int>& ratings) {
		vector<int> f(ratings.size());
		int sum = 0;
		for (int i = 0; i < ratings.size(); i++)
		{
			sum += solve(ratings, f, i);
		}
		return sum;
	}
	int solve(const vector<int> & ratings, vector<int> & f, int i)
	{
		if (f[i] == 0)
		{
			f[i] = 1;
			if (i > 0 && ratings[i] > ratings[i - 1])
			{
				f[i] = solve(ratings, f, i - 1) + 1;
			}
			if (i < ratings.size() - 1 && ratings[i] > ratings[i + 1])
			{
				f[i] = max(f[i], solve(ratings, f, i + 1) + 1);
			}
		}
		return f[i];
	}
};