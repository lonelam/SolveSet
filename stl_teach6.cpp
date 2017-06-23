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
    for (int x : v)
    {
        cout << x <<",";
    }
    cout << endl;
}
