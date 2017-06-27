#include <set>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int main()
{
    set<int> ST = {6,7,4,2,5,1,3,3};
   //cout << log2(5000000)<<endl;
    for (int x : ST)
    {
        cout << x <<",";
    }
    cout << endl;
    ST.insert(8);
    ST.insert(-1);
    ST.erase(2);
  //  auto it = ST.find(4);
    auto it2 = ST.lower_bound(8);

    for (int x : ST)
    {
        cout << x <<",";
    }
    cout << endl;
    cout << *ST.begin() << endl;
    cout << *ST.rbegin() << endl;
    typedef pair<int,int> pii;
    map<string, int> mp;// = ({"one":1}, {"two":2});
    mp["one"] = 1;
    mp["two"] = 2;
    mp.insert({"three":3});

}
