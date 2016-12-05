#include<string>
#include<map>
#include<set>
#include<iterator>
#include<iostream>
//#include<bits/stdc++.h>
#include<vector>
using namespace std;
struct vol
{
    int lev;
    string name;
    vector<vol> cat;
    map<string, int> ind;
    set<string> book;
    vol(int l, string lt,string n):lev(l),name(n)
    {
        int i;
        for(i = 0; i < lt.length();i ++ )
        {
            if(lt[i]=='/')
            {
                cat.push_back(vol(l + 1, lt.substr(i + 1, lt.length() - i - 1),lt.substr(0, i)));
                ind[lt.substr(0, i)] = 0;
                break;
            }
        }
        if(i == lt.length())
        {
            book.insert(lt);
        }
    }
    vol():lev(-1),name("") {}
    bool operator<(vol & b)
    {
        return name < b.name;
    }
    void ins(string lt)
    {
        int i;
        for(i = 0; i < lt.length(); i++)
        {
            if(lt[i] == '/')
            {
                string cname = lt.substr(0, i);
                auto res = ind.find(cname);
             //  cout<<"debug: \""<<cname<<"\"";
               // cout<<distance(res, ind.end())<<endl;
                if(res!= ind.end())
                {
                    cat[res->second].ins(lt.substr(i + 1, lt.length() - i - 1));
                }
                else
                {
                    ind[cname] = cat.size();
                    cat.push_back(vol(lev + 1,lt.substr(i + 1, lt.length() - i - 1),cname ));
                }
                break;
            }
        }
        if(i == lt.length())
        {
            book.insert(lt);
        }
    }
    void show()
    {
        for(int i = 0; i < lev; i++)
        {
            cout<<"    ";
        }
       // cout<<"debug :"<<name<<endl;
      // cout<<"debug: "<<ind.size()<<"  ";
        if(lev != -1)cout<<name<<endl;
        for(auto x : ind)
        {
            cat[x.second].show();
          //  cout<<"debug: "<<cat[x.second].name<<endl;
        }
        for(auto s : book)
        {
            for(int i = -1; i < lev; i++)
            {
                cout<<"    ";
            }
            cout<<s<<endl;
        }
    }
};
int main()
{
    int kase = 1;
    vol root;
    string line;
 //   cout<<"Case "<<kase++<<":\n";
    while(getline(cin, line))
    {
        if(line != "0")
        {
            root.ins(line);
        }
        else
        {
            cout<<"Case "<<kase++<<":\n";
            root.show();
            root.book.clear();
            root.cat.clear();
            root.ind.clear();
        }
    }
}

