#include<iostream>
#include<chrono>

using namespace std;

int main()
{
	using namespace chrono;
	typedef chrono::duration<int, ratio<3600>> hour_t;
	typedef chrono::duration<int, milli> millisecond_t;

	const hour_t one_hour(1);
	const millisecond_t ms(one_hour);
	const auto secs = duration_cast<seconds> (0.5h);
	time_point<system_clock, seconds> one_sec(1h);
	for (int i = 0; i < 1000; i++)
	{
		cout << system_clock().now().time_since_epoch().count() << endl;
	}
	system("pause");
}