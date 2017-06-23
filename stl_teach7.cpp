#include <bits/stdc++.h>
using namespace std;
class acmer
{
public:
    string name;
    int codeforces_score;
    bool operator<(const acmer & rhs) const {return codeforces_score < rhs.codeforces_score;}
};
int main()
{
    vector<acmer> acmclub = {{"lonelam", -1}, {"onisac", 1724}};
    acmclub.emplace_back( acmer({"Oneday", 1700}));
    sort(acmclub.begin(), acmclub.end());
    for (acmer people: acmclub)
    {
        cout << people.name << " : " << people.codeforces_score << endl;
    }
}
