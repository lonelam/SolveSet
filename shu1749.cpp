#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string add(string a, string b)
{
    if(a.size() > b.size())//a size < b size
    {
        return add(b, a);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int n = max(a.size() , b.size()) + 1;
    string ans(n, '0');
    int carry = 0;
    for(int i =0;i < a.size(); i++)
    {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 8;
        ans[i] = sum % 8 + '0';
    }
    for(int i = a.size(); i < b.size(); i++)
    {
        int sum = (b[i] - '0') + carry;
        carry = sum / 8;
        ans[i] = sum % 8 + '0';
    }
    ans[b.size()] = carry + '0';
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < n; i++)
    {
        if (ans[i] != '0')
        {

            return ans.substr(i, n - i);
        }
    }
    return ("0");
}
int main()
{
    string a, b;
    while(cin >> a >> b)
    {
        cout << a << "+" << b << "=" << add(a, b) << endl;
    }
}
