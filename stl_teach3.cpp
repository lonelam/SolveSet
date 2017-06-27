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
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ",";
    }
    cout << endl;
    //cout << *v.end() <<endl;

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
    //w == vector({3,4});
    vector<int> u(v.begin() + 2, v.end());
    //u== vector({3,4});
    cout << (w == u) << endl;
}
