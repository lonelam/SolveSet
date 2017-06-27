#include <bits/stdc++.h>
using namespace std;
template<typename T>
class acmer
{
public:
    T name;
    int codeforces_score;
    int qq;
    bool is_master()
    {
        return codeforces_score >= 1900;
    }
};
int main()
{
    acmer<int> nerd;
    nerd.name = 12345;//"lonelam";
    nerd.codeforces_score = 0;
    nerd.qq = 514334426;
    acmer<string> leader = {"onisac", 1900, 10000};
    cout << nerd.name << " "
    << nerd.is_master() << endl;
    cout << leader.name << " "
    << leader.is_master() << endl;
}
