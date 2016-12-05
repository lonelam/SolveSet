#include<cstdio>

using namespace std;
const int maxf = 2005;
bool nprime[maxf];
int ps[200];
int np = 0;
void init()
{
    nprime[1] = nprime[0] = true;
    for(int i = 2; i < maxf; i++)
    {
        if(!nprime[i])
        {
            for(int j = i + i; j < maxf; j+= i)
            {
                nprime[j] = true;
            }
            ps[np++] = i;
        }
    }
}


