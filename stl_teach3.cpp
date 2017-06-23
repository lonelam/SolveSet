#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int> v(2, 1);
    cout << v.size() << endl;
    v.push_back(3);
    cout << v.size() << endl;
    v.emplace_back(4);//C++11
    for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
    {
        cout << *i << ",";
    }
    cout << endl;
    //C++11
    for (auto i = v.rbegin(); i != v.rend(); i++)
    {
        cout << *i << ",";
    }
    cout << endl;
    vector<int> w;
    w.insert(w.begin(), v.begin() + 2, v.end());
    vector<int> u(v.begin() + 2, v.end());
    cout << (w == u) << endl;
}
