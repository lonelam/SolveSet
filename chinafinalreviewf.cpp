#include<iostream>
#include<map>
#include<string>
using namespace std;
char ch[] = {'A', 'C', 'T', 'G'};
bool isvalid(map<char, int> & cnt, int N)
{
    for (int i = 0; i < 4; i++)
    {
        if (cnt[ch[i]] > N)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int t;
    string line;
    while(cin >> t)
    while(t--)
    {
        map<char, int> cnt;
        cin >> line;
        int N = line.length() / 4;
        int l = 0, r = 0;
        for (int i = 0; i < line.length(); i++)
        {
            cnt[line[i]]++;
        }
        int ans = line.length();
        while(l < line.length())
        {
            while(r < line.length() && !isvalid(cnt, N))
            {
                cnt[line[r]]--;
                r++;
            }
            if (isvalid(cnt, N))
                ans = min(ans, r - l);
            cnt[line[l]]++;
            l++;
        }
        cout << ans <<endl;
    }
}
