#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int dd[100005],num[100005],cnt;
struct node{
    int x,y,lab;
    bool operator <(const node& a)const{
        return y<a.y;
    }
}e[50005];
vector<int>ans;
priority_queue<node,vector<node>,less<node> >sp;
bool cmp(node a,node b){
    return a.x<b.x;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,i,j;
        scanf("%d",&n);
        memset(dd,0,sizeof(dd));
        cnt=0;
        for(i=1;i<=n;i++){
            scanf("%d%d",&e[i].x,&e[i].y);
            e[i].lab=i;
            num[++cnt]=e[i].x;
            num[++cnt]=e[i].y;
        }
        sort(e+1,e+1+n,cmp);
        int mix=0;
        sort(num+1,num+1+cnt);
        cnt=unique(num+1,num+1+cnt)-num-1;
        for(i=1;i<=n;i++){
            e[i].x=lower_bound(num+1,num+1+cnt,e[i].x)-num;
            e[i].y=lower_bound(num+1,num+1+cnt,e[i].y)-num;
        }
        e[n+1].x=-111;
        int now=1;
        while(!sp.empty())sp.pop();
        ans.clear();
        for(i=1;i<=cnt;i++){
            while(e[now].x==i){
                sp.push(e[now]);
                mix++;
                dd[e[now].y+1]--;
                now++;
            }
            mix+=dd[i];
            while(mix>=3){
                node f=sp.top();
                sp.pop();
                mix--;
                dd[f.y+1]++;
                ans.push_back(f.lab);
            }
        }
		
        sort(ans.begin(),ans.end());
        int dt=ans.size();
        printf("%d\n",dt);
        for(i=0;i<dt;i++){
            printf("%d",ans[i]);
            if(i==dt-1)break;
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}
