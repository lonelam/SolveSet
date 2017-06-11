
#include <stdio.h>
struct node{
    int sizes;
    int value;
    double vs;
};
int main(){
    int n,v,casenum=1;
    struct node s[60],t;
    while(scanf("%d%d",&n,&v)==2){
        int i,j,sum=0;
        for(i=0;i<n;i++)scanf("%d",&s[i].value);
        for(i=0;i<n;i++)scanf("%d",&s[i].sizes);
        for(i=0;i<n;i++)s[i].vs=(double)s[i].value/s[i].sizes;
        for(i=0;i<n;i++)
            for(j=0;j<n-1;j++)
                if(s[j].vs<=s[j+1].vs){
                    t=s[j];s[j]=s[j+1];s[j+1]=t;
                }
        for(i=0;i<n;i++){
            if(s[i].vs==s[i+1].vs)
                if(s[i].sizes>=s[i+1].sizes){
                    t=s[i];s[i]=s[i+1];s[i+1]=t;
                }
        }
        for(i=0;i<n;i++){
            if((v-s[i].sizes)>=0){
                sum+=s[i].value;
                v-=s[i].sizes;
            }
        }
        printf("Case %d:%d\n",casenum,sum);
        casenum++;
    }
    return 0;
}
