#include<bits/stdc++.h>
using namespace std;
string table[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };
int main()
{
    string fir, sec;
    while(cin >> fir >> sec)
    {
        int a1 = find(table, table + 7, fir) - table;
        int a2 = find(table, table + 7, sec) - table;
        if(a1 == a2 || (a2 + 7 - a1)% 7 == 2 || (a2 + 7 - a1) % 7 == 3)
        {
            cout<<"YES\n";
        }
        else
        {

            cout<<"NO\n";
        }
    }
}
