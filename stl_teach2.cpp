#include <bits/stdc++.h>
using namespace std;
class acmer
{
public:
    string name;
    int codeforces_score;
    int qq;
    bool is_master()
    {
        return codeforces_score >= 1900;
    }
};
int main()
{
    acmer nerd;
    nerd.name = "lonelam";
    nerd.codeforces_score = 0;
    nerd.qq = 514334426;
    acmer leader = {"onisac", 1900, 10000};
    cout << nerd.name << " "
    << nerd.is_master() << endl;
    cout << leader.name << " "
    << leader.is_master() << endl;
}
