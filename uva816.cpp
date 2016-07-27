#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<queue>
#include<string>
using namespace std;
enum dirs{N,E,S,W};
enum turns {F,L,R};
const int MAZE_SIZE = 11;
typedef pair<int,int> step;
typedef pair<int,int> pos;
typedef pair<pos,dirs> mov;
map<dirs,step> walk {{N,{-1,0}},{E,{0,1}},{S,{1,0}},{W,{-1,0}}};
bool visited[MAZE_SIZE][MAZE_SIZE][4];
mov par[MAZE_SIZE][MAZE_SIZE][4];
turns chr2trn(char x)
{
    switch(x)
    {
    case 'F':
        return F;
    case 'L':
        return L;
    case'R':
        return R;
    }
}
dirs left_turn(dirs a)
{
    return dirs((a+1)%4);
}
dirs right_turn(dirs b)
{
    return dirs((b+3)%4);
}
mov turn(pos orig, dirs dd,turns trn)
{
    if(trn == F)
    {
        return {{orig.first+walk[dd].first,orig.second+walk[dd].second},dd};
    }
    if(trn == L)
    {
        return {{orig.first+walk[left_turn(dd)].first,orig.second+walk[left_turn(dd)].second},left_turn(dd)};

    }
    if(trn == R)
    {
        return {{orig.first+walk[right_turn(dd)].first,orig.second+walk[right_turn(dd)].second},right_turn(dd)};
    }
}
vector<turns> mp[MAZE_SIZE][MAZE_SIZE][4];
int g_x,g_y,e_x,e_y;
mov bfs(int x,int y,dirs orig_d)
{
    queue<mov> cur,nex;
    cur.push(turn({x,y},orig_d,F));

    while(!cur.empty())
    {
        while(!cur.empty())
        {
            mov stp = cur.front();
            cur.pop();
            visited[stp.first.first][stp.first.second][stp.second] = true;
            for(turns tn:mp[stp.first.first][stp.first.second][stp.second])
            {
                mov temp = turn(stp.first,stp.second,tn);
                if(!visited[temp.first.first][temp.first.second][temp.second])
                {
                    if(temp.first.first == g_x&&temp.first.second == g_y)
                    {
                        return temp;
                    }
                    par[temp.first.first][temp.first.second][temp.second] = stp;
                    nex.push(temp);
                }
            }
        }
        cur = nex;
    }
    return {{0,0},N};
}

void output(mov t)
{
    if(t.first.first == 0 && t.first.second == 0)
    {
        cout<<"  No Solution Possible"<<endl;
    }
    else
    {
        vector<mov> out;
        out.push_back(t);
        while(t.first.first!=e_x||t.first.second != e_y)
        {
            t = par[t.first.first][t.first.second][t.second];
            out.push_back(t);
        }
        int ten_cnt = 0;
        for(auto i = out.rbegin();i!=out.rend();i++)
        {
            if(ten_cnt==0)
            {
                cout<<"  ";
            }
            cout<<'('<<i->first.first<<','<<i->first.second<<')';
            if(ten_cnt<9)
            {
                cout<<' ';
                ten_cnt++;
            }
            else
            {
                cout<<endl;
                ten_cnt = 0;
            }
        }
    }
}

int main()
{
    string title;
    char ttmp;
    dirs ori_d;
    while(getline(cin,title))
    {
        if(title == "END")
        {
            return 0;
        }
        cout<<title<<endl;
        cin>>e_x>>e_y;
        cin>>ttmp;
        cin>>g_x>>g_y;
        switch(ttmp)
        {
        case 'N':
            ori_d = N;
            break;
        case 'S':
            ori_d = S;
            break;
        case 'E':
            ori_d = E;
            break;
        case 'W':
            ori_d = W;
            break;
        }
        int node_x,node_y;
        dirs nd_d;
        string tstr;
        while(cin>>node_x&&node_x)
        {
            cin>>node_y;
            while(cin>>tstr)
            {
                if(tstr[0] == '*')
                {
                    break;
                }
                switch(tstr[0])
                {
                case 'N':
                    nd_d = N;
                    break;
                case 'S':
                    nd_d = S;
                    break;
                case 'E':
                    nd_d = E;
                    break;
                case 'W':
                    nd_d = W;
                    break;
                }
                for(auto i = tstr.begin()+1;i!=tstr.end();i++)
                {
                    mp[node_x][node_y][nd_d].push_back(chr2trn(*i));

                }
            }
        }
        output(bfs(e_x,e_y,ori_d));

    }
}
