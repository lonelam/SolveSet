#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
int root,tot;
int pre[MAXN],ch[MAXN][2],key[MAXN];

int newnode(int x,int fa){
    int ret = ++tot;
    key[ret]= x;
    pre[ret] = fa;
    ch[ret][0] = ch[ret][1] = 0;
    return ret;
}

void push_down(int r){
    if(!r)return;
}

void push_up(int x) {

}

void rotate(int x, int d) {
    const int y = pre[x];
    ch[y][!d] = ch[x][d];
    if (ch[x][d])pre[ch[x][d]] = y;
    pre[x] = pre[y];
    if (ch[pre[y]][0] == y)ch[pre[x]][0] = x;
    else if (ch[pre[y]][1] == y)ch[pre[x]][1] = x;
    pre[y] = x;
    ch[x][d] = y;
    push_up(y);
}

bool _splay_parent(int x, int &y,int goal) {
    return (y = pre[x]) != goal && (ch[y][0] == x || ch[y][1] == x);
}

void splay(int x, int goal) {
    push_down(x);
    if(goal == 0)root = x;
    for (int y, z; _splay_parent(x, y,goal);) {
        if (_splay_parent(y, z,goal)) {
            push_down(z);
            push_down(y);
            push_down(x);
            int d = y == ch[z][0];
            if (x == ch[y][d])rotate(x, d ^ 1), rotate(x, d);
            else rotate(y, d), rotate(x, d);
        } else {
            push_down(y), push_down(x);
            rotate(x, x == ch[y][0]);
            break;
        }
    }
    push_up(x);
}

int insert(int r,int x){
    if(key[r] == x){
        return 1;
    }else{
        int d = x > key[r];
        if(ch[r][d]){
            return insert(ch[r][d],x);
        }
        int cur = newnode(x,r);
        ch[r][d] = cur;
        splay(cur,0);
        return 0;
    }
}


int main(){
    ios::sync_with_stdio(0);
    int n;
    cin >>n;
    long long ans =0;
    root = 0;
    for(int i = 0; i <n ; i++){
        int num;
        cin >> num;
        if(i == 0){
            ans = num;
            root = newnode(num,0);
        }else{
            if(insert(root,num))continue;
            else{
                int L = ch[root][0];
                long long tmp = LONG_MAX;
                if(L){
                    while(ch[L][1]){
                        L = ch[L][1];
                    }
                    tmp = min(tmp, (long long)num - key[L]);
                }
                int R = ch[root][1];
                if(R){
                    while(ch[R][0]){
                        R = ch[R][0];
                    }
                    tmp = min(tmp,(long long)key[R] - num);
                }
                ans += tmp;
            }
        }
    }
    cout <<ans<<endl;



    return 0;
}