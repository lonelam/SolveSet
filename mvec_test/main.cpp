
#define debug
#include "cool_vec.hpp"


int main()
{
	pvector<int> v1, v2 = make_pair(1,2);
	tvector<long long> v3;
	Vector v4 = { 0, 3, 3 };
	Vector v5 = {0, 0, 0};
	cout << v4.Length()<<endl;
	cout<<v4.Angle(v5)<<endl;
	cin >> v1;
	//v2 = v1;
	cout << v1 << endl;
	cout << v2 << endl;
	cout << v1.Dot (v2) << endl;
	cin >> v3;

	cout << v3 << endl;
	cout << v4 << endl;
	cin >> v4;
	cout << v4 << endl;
//	system("pause");
}
//
