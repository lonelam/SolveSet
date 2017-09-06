#include <bits/stdc++.h>
#include <string>
using namespace std;
const int maxn = 2500 +100;
char s[maxn];
int n;
char t[maxn];
char re[maxn * 100];
int m;
int main()
{
    int T;
    scanf("%d", &T);
    getchar();
        while(T--)
        {
            gets(s); gets(t);//("%s%s", s, t);
        /*    for (int i = 0; i < 500; i++)
            {
                s[i] = 'a' + (i*5432623464%26);
                s[i+500] = 'c';
            }
            s[1000] = '\0';
            for (int i = 0; i < 500;i++)
            {
                t[i * 2] = '.';
                t[i * 2 +1] = '*';
                t[i * 2  + 1000] = '.';
                t[i * 2 + 1001] = '*';
            }
            t[2000] = 'c';
            t[2001] = '\0';*/
            n = strlen(s);
            m = strlen(t);
            int p = 0;
            int cnt = 0;
            for (int i = 0; i < m; i++)
            {
                if (t[i]=='.')
                {
                    strcpy(re + p, "(.)");
                    cnt++;
                    p += 3;
                }
                else if (t[i] == '*' && t[i-1] =='.')
                {
                    char tmp[100];
                    sprintf(tmp, "\\%d*?", cnt);
                  //  tmp = "\\" + tmp + "*";
                    strcpy(re + p, tmp);
                    p += strlen(tmp);
                }
                else
                {
                    re[p++] = t[i];
                }
            }
            re[p] ='\0';
            printf("%s\n", re);
            //cout << n << " "<< m <<endl;
           // memset(mem,-1,sizeof(mem));

            regex reg(re);
            if (regex_match(s,reg))
            {
                puts("yes");
            }
            else
            {
                puts("no");
            }
        }

}
/*
100
ab
(.)*
yes
ab
\w*
yes
ab
(.)\1*
no
aaaaaaaaaaab
(.)\1*b
yes
aaaaaaaaaaabbbbbbbc
(.)\1(.)\1c
no
(.)\1(.)\2c
a
no
aaaaaaaaaaabbbbbbbc
(.)\1(.)\2c
no
aaaaaaaaaaabbbbbbbc
(.)\1*(.)\2*c
yes
aaaaaaaaaaabbbbbbbc
(.)\1(.)\1*c
no
*/
