#include<cstdio>
typedef int ll;
using namespace std;
    char s[10000005];

int main()
{
    int kase = 1;
    int remain = 0;
    char c;
    const int f = 10001;
    while(scanf("%s",s)!=EOF)
    {
        for(char * c = s; ; c++)

        //printf("debug%d\n",c);
        if(*c == '\0')
        {
            if(remain)
            {
                printf("Case #%d: NO\n",kase++);
            }
            else
            {
                printf("Case #%d: YES\n",kase++);
            }
            remain = 0;
            break;
        }
        else
        {
            remain = (remain * 10 + *c - '0') % f;
        }
    }
}
int main_1()
{
    int kase =1;
    ll remain = 0;
    const ll f = 73 * 137;
    int c;

    while(true)
    {
        c = getchar();
        if(c == EOF)
        {
            if(remain)
    {
        printf("Case #%d: NO\n",kase++);
    }
    else
    {
        printf("Case #%d: YES\n",kase++);
    }
    return 0;
        }
        //printf("debug%d\n",c);
        if(c == '\n')
        {
            if(remain)
            {
                printf("Case #%d: NO\n",kase++);
            }
            else
            {
                printf("Case #%d: YES\n",kase++);
            }
            remain = 0;

        }
        else
        {
            remain = (remain * 10 + c - '0') % f;
        }
    }

}
