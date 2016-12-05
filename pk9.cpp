#include<bits/stdc++.h>
using namespace std;

const int maxn = 10005;
const int inf = 0x3f3f3f3f;
const int maxr = 20005;
int m, n, r;//A - n, B- m
int xb, t_A, t_B;//defend time
int xa;
int L_A, L_B;
int Ta[maxn];
int Tac[maxn];
int Da[maxn];
int Tb[maxn];
int Tbc[maxn];
int Db[maxn];

struct missile
{
    int Reach, Run, Damage;
    bool operator<(const missile & b)const
    {
        return Reach < b.Reach;
    }
};

missile R[maxr];
int Rtr[maxr];
int Trc[maxr];
int Dr[maxr];

void init()
{
    r = m;
    L_B = xb + t_B + 1;
    for(int i = 0;i < m; i++)
    {

        R[i].Reach = Tb[i] + Tbc[i];
        R[i].Damage = Db[i];
        R[i].Run = Tbc[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(Ta[i] + Tac[i] < L_B)
        {
            R[r].Reach = Ta[i] + 2 *Tac[i];
            R[r].Run = Tac[i];
            R[r++].Damage = Da[i];
        }
    }
    sort(R, R + r);
}

int solve()
{
    init();
    set<int> kept, nex;
    L_A = R[0].Reach + t_A + 1;
    int iter = 0;
    int ans = inf;
    int sum = 0;
    int last;
    for(int i = 0; i < r; i++)
    {
        if(R[i].Reach < L_A)
        {
            if(L_A > L_B)
            {
                int hit_n = (L_B - R[i].Reach)/R[i].Run;
                if(hit_n & 1)
                {
                    if(R[i].Reach + R[i].Run *(hit_n + 1) < L_A)
                    {
                        continue;
                    }
                    else
                    {
                        sum += R[i].Damage;
                      //  printf("debug:%d\n",sum);
                        kept.insert(i);
                    }
                }
            }
            else
            {
                int hit_n = (L_A - R[i].Reach)/R[i].Run;
                if(hit_n & 1 || (R[i].Reach + R[i].Run * (hit_n + 1) < L_B))
                {
                    sum += R[i].Damage;
                 //   printf("debug:%d\n",sum);
                    kept.insert(i);
                }
            }
            last = i;
        }
        else
        {
            sum += R[i].Damage;
        }
    }
    last++;
    ans = sum;
    for(int i = 1; i < r; i++)
    {
        L_A = R[i].Reach + t_A + 1;
        if(kept.find(i - 1)!= kept.end())
        {
            kept.erase(i - 1);
           // sum -= R[i - 1].Damage;
            //printf("debug:%d\n",sum);
        }
        else
        {
            sum += R[i - 1].Damage;
        }
        for(int j = last; j < r && R[j].Reach < L_A;j++,last++)
        {
          //  kept.insert(j);
                if(L_A > L_B)
                {
                    int hit_n = (L_B - R[j].Reach)/R[j].Run;
                    if(hit_n & 1)
                    {
                        if(R[j].Reach + R[j].Run *(hit_n + 1) < L_A)
                        {
                          //  sum -= R[j].Damage;
                        }
                        else
                        {
                            sum += R[j].Damage;
                                    //    printf("debug:%d\n",sum);

                            nex.insert(j);
                        }
                    }
                }
                else
                {
                    int hit_n = (L_A - R[j].Reach)/R[j].Run;
                    if(hit_n & 1 || (R[j].Reach + R[j].Run * (hit_n + 1) < L_B))
                    {
                        sum += R[j].Damage;

                        nex.insert(j);
                    }
                    else
                    {
                       // sum -= R[i].Damage;
                    }
                }
        }

        for(int x : kept)
        {
            if(R[x].Reach < L_A)
            {
                if(L_A > L_B)
                {
                    int hit_n = (L_B - R[x].Reach)/R[x].Run;
                    if(hit_n & 1)
                    {
                        if(R[x].Reach + R[x].Run *(hit_n + 1) < L_A)
                        {
                            sum -= R[x].Damage;
                               //         printf("debug:%d\n",sum);

                        }
                        else
                        {
                            nex.insert(x);
                        }
                    }
                }
                else
                {
                    int hit_n = (L_A - R[x].Reach)/R[x].Run;
                    if(hit_n & 1 || (R[x].Reach + R[x].Run * (hit_n + 1) < L_B))
                    {
                        //sum += R[i].Damage;
                        nex.insert(x);
                    }
                    else
                    {
                        sum -= R[i].Damage;
                       // printf("debug:%d\n",sum);

                    }
                }
            }
        }
        kept.clear();
        swap(kept, nex);
        ans = min(ans, sum);
    }
    return ans;
}
int main()
{
    while(scanf("%d%d",&t_A,&t_B)!=EOF)
    {
        scanf("%d",&xb);
        scanf("%d%d",&n, &m);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d", Ta + i, Tac + i, Da + i);
        }
        for(int j = 0; j < m; j++)
        {
            scanf("%d%d%d",Tb + j, Tbc + j, Db + j);
        }
        printf("%d\n",solve());
    }
    return 0;
}
