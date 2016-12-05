#include<bits/stdc++.h>

using namespace std;

map<string, int> m;
int main()
{
    ios::sync_with_stdio(false);
    string line;
    while(getline(cin, line))
    {
        if(line == "####")
        {
            int larger = 0;
            string ans;
            for(auto x : m)
            {
                if(larger < x.second)
                {
                    larger = x.second;
                    ans = x.first;
                }
                else if(larger == x.second && ans > x.first)
                {
                    ans = x.first;
                }
            }
            cout<<ans<<":"<<larger<<endl;
            m.clear();
            continue;
        }
        int bg = 0;
        string last = "#";
        for(int i = 0; i < line.length(); i++)
        {
            if(!islower(line[i]))
            {
                if(bg <= i && islower(line[bg]))
                {
                    if(last != "#")
                        m[last + line.substr(bg, i - bg)]++;
                       // cout<<"debug"<<bg<<" "<<last<<"  "<<line.substr(bg , i - bg)<<endl;
                    if(line[i]== ' ')
                    {
                            last = line.substr(bg, i - bg + 1);
                    }
                    else
                    {
                        last = "#";
                    }
                }
                else if(bg <= i)
                {
                    if(line[i] != ' ')
                    {
                        last = "#";
                    }
                }
                bg = i + 1;
            }

        }
        if(bg < line.length() && last != "#")
        {
            m[last + line.substr(bg, line.length() - bg)]++;
        }
    }
}
