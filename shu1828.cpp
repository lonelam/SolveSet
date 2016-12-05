#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t;
    string line;
    while(cin >> t)
    {
        while(t--)
        {
            cin >> line;
            int carry = 0;
            for(int i = 0; i < line.size(); i++)
            {
                carry *= 10;
                carry += line[i] - '0';
                carry %= 11;
            }
            if(carry)
            {
                cout << "No\n";
            }
            else
            {
                cout << "Yes\n";
            }
        }
    }
}
