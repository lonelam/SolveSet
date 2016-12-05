#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool used[1001];
int k,n;
double lowest;
int A[1001];//¥Ê¥¢
int main()
{
	cout.setf(ios::fixed);
	cout.precision(2);
	while (cin >> n >> k)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		
		sort(A, A + n);//≈≈–Ú
		int sum = 0;
		for (int i = 0; i < k; i++)
		{
			sum += A[i];
		}
		double avg = sum * 1.0 / k;
		double diff = 0;
		for (int i = 0; i < k; i++)
		{
			diff += (A[i] - avg) * (A[i] - avg);
		}
		lowest = diff;
		//º∆À„µ±«∞◊¥Ã¨µƒ∑Ω≤Ó
		for (int i = k; i < n; i++)
		{
			sum += A[i];
			int deleted = i - k;
			sum -= A[deleted];
			avg = sum*1.0 / k;
			diff = 0;
			for (int j = i; j > deleted; j--)
			{
				diff += (A[j] - avg) * (A[j] - avg);
			}
			lowest = min(lowest, diff);
		}
		cout << lowest / k << endl;

	}
}