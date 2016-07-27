#include<stdio.h>
#include<string.h>
int prime[40]={0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0},n;//素数打表，因为n最大是20，所以只要打到40
int visited[21],a[21];
void dfs(int num)//深搜
{
   int i;
   if(num==n&&prime[a[num-1]+a[0]])  //满足条件了，就输出来
   {
       for(i=0;i<num-1;i++)
           printf("%d ",a[i]);
       printf("%d\n",a[num-1]);
   }
   else
   {
       for(i=2;i<=n;i++)
       {
           if(visited[i]==0)//是否用过了
           {
               if(prime[i+a[num-1]]) //是否和相邻的加起来是素数
               {
                   visited[i]=-1;//标记了
                   a[num++]=i;//放进数组
                   dfs(num); //递归调用
                   visited[i]=0; //退去标记
                   num--;
               }
           }
       }
   }
}    
int main()
{
      int num=0;
      while(scanf("%d",&n)!=EOF)
      {
         num++;
         printf("Case %d:\n",num);
         memset(visited,0,sizeof(visited));
         a[0]=1;
         dfs(1);
         printf("\n");
      }
      return 0;
}
