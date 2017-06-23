
#include<stdio.h>
#include <string>
#include <iostream>
#include<math.h>
using namespace std;
 int main(){
     for (int kase = 1; kase < 10; kase++)
    {/*
        string fname_base  = ".in";
        string fname;
        fname = string(1, kase + '0') + fname_base;
        freopen(fname.c_str(), "r", stdin);
        fname_base = ".out";
        fname = string(1, kase + '0') + fname_base;
        freopen(fname.c_str(), "w", stdout);*/
 int n,t,i;
     scanf("%d",&t);
      for(i=1;i<=t;i++){
	 scanf("%d",&n);
	printf( "%d\n", (int)sqrt((double)n));
      }
    }

      return 0;
}
