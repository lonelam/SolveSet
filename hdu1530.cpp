
#include <stdio.h>
int  clique( int n,int *u,bool mat[][55],int size,int &max){
    int i,j,vn,v[55];
    if (n){
        if (size+n<=max) return 0;
        for (i=0;i<n+size-max && i<n;i++){
            for (j=i+1,vn=0;j<n;j++){
                if (mat[u[i]][u[j]])
                    v[vn++]=u[j];
            }
            clique(vn,v,mat,size+1,max);
        }
    }
    else if (size>max){
        max=size;
    }
    return 0;
}
int maxclique(int n,bool mat[][55]){
    int max=0,i,j;
    int vn,v[55];
    for (i=n-1;i>=0;i--){
        for (vn=0,j=i+1;j<n;j++){
            if (mat[i][j])v[vn++]=j;
        }
        clique(vn,v,mat,1,max);
    }
    return max;
}

int main(){
    //freopen ("a.txt","r",stdin);
    int n,i,j;
    bool mat[55][55];
    while (scanf("%d",&n)&&n){
        for (i=0;i<n;i++){
            for (j=0;j<n;j++)
                scanf("%d",&mat[i][j]);
        }
        printf ("%d\n",maxclique(n,mat));
    }
    return 0;
}
