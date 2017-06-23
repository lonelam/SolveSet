#include <set>
#include <iostream>
using namespace std;
int main()
{
    set<int> ST = {6,7,4,2,5,1,3,3};
    for (int x : ST)
    {
        cout << x <<",";
    }
    cout << endl;
    ST.insert(8);
    ST.insert(-1);
    ST.erase(2);
    for (int x : ST)
    {
        cout << x <<",";
    }
    cout << endl;
    cout << *ST.begin() << endl;
    cout << *ST.rbegin() << endl;
}
