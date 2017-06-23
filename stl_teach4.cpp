#include <deque>
#include <iostream>
using namespace std;
int main()
{
    deque<int> Q(2, 1);
    Q.push_back(4);
    Q.push_front(-1);
    for (auto i = Q.begin(); i != Q.end(); i++)
    {
        cout << *i <<",";
    }
    cout << endl;
    Q.pop_back();
    for (int x : Q)
    {
        cout << x << ",";
    }
    cout << endl;
    Q.emplace_front(10);
    cout << Q[1] << endl;
}
