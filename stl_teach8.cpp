#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class acmer
{
public:
    string name;
    int codeforces_score;
    bool operator<(const acmer & rhs) const {return name < rhs.name;}
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
    cout << binary_search(acmclub.begin(), acmclub.end(), acmer({"Oneday", -1})) << endl;
    cout << binary_search(acmclub.begin(), acmclub.end(), acmer({"12Dong", -1})) << endl;
}
