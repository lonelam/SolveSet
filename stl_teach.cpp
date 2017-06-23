#include <bits/stdc++.h>
namespace alpha
{
    int member = 1;
}
int member = 2;
int call_member() {return member;}
int main()
{
    int member = 3;
    {
        int member = 4;
        std::cout << member <<std::endl;
    }
    using std::cout;
    cout << member <<std::endl;
    cout << call_member() << std::endl;
    using namespace std;
    cout << alpha::member << endl;
}
