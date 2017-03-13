#include<bits/stdc++.h>
using namespace std;

int main()
{
    char num[300];
    int t,k;
    cin>>t;
    while(t--){
        scanf("%s%d",num,&k);

        while(k){
            int len = strlen(num);
            int st_i = 1;
            int pos = 0;
            while(num[st_i]>=num[st_i-1] && st_i<len){
                pos = st_i;
                st_i++;
            }
            char change[300];
            int j = 0;
            for(int i=0;i<len;++i){
                if(i!=pos)change[j++] = num[i];
            }
            change[j++] = '\0';
            for(int i=0;i<j;++i)num[i] = change[i];
            k--;
        }
        int L = strlen(num);
        //cout<<num<<endl;
        int i = 0;
        while(num[i] == '0' && i<L)i++;
        if(i==L)putchar('0');
        else
            for(int j=i;j<L;++j)printf("%c",num[j]);
        printf("\n");
    }
    return 0;
}
