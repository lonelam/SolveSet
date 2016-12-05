#include<bits/stdc++.h>
using namespace std;
int main()
{
    string line;
    while(cin >> line)
    {
        int ans = 0;
        bool rt;
        for (int i = 0, j= 1; i < 12;i++)
        {
            if(line[i] != '-')
            {
                ans += (line[i] - '0') * j;
                j++;
            }
        }
        if (line.back() == 'X' ? ans % 11 == 10 : ans % 11 == line.back() - '0')
        {
            rt = true;
        }
        else
        {
            rt = false;
            line.back() = ans % 11 == 10 ? 'X':ans % 11 + '0';
        }
        if (rt)
        {
            cout << "Right\n";
        }
        else
        {
            cout << line << endl;
        }
    }


}
