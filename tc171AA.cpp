#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
class PingPongQueue
{
public:
    PingPongQueue() {}
    vector <int> whoPlaysNext(vector <int> skills, int N, int K)
    {
        queue<int> Q;
        for (int skill : skills)
        {
            Q.push(skill);
        }
        int a = Q.front();
        Q.pop();
        int b = Q.front(), wins = 0;
        Q.pop();
        if (a < b) swap(a,b);
        for (int i = 0; i < K; i++)
        {
            Q.push(b);
            wins++;
            b = Q.front();
            Q.pop();
            if (wins == N)
            {
                wins = 0;
                Q.push(a);
                a = Q.front();
                Q.pop();
            }
            if (a < b)
            {
                wins = 0;
                swap(a,b);
            }

        }
        return {b, a};
     //   sort(skills.begin(), skills.end());

    }
};
