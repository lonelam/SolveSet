#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;
int main()
{
    vector<int> v = {6,7,4,2,5,1,3};
    sort(v.begin(), v.end());
    for (int x : v)
    {
        cout << x <<",";
    }
    cout << endl;
    sort(v.begin(), v.end(), greater<int>());
   // int & x = *v.begin() + i;
    for (int & x : v)
    {
        x = 1000;
        cout << x <<",";
    }
    cout << endl;
    for (int x : v)
    {
        cout <<x  << ",";
    }
    cout << endl;
}
