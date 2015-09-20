#include <stdio.h>
#include <string.h>
#define MOD 1000000
#define lli long long int

using namespace std;

lli memo[1005];

lli DP(int total){
      if(memo[total]!=-1) return memo[total];
      if(total==1) return memo[total] = 1;
      lli res = 0;
      for(int i=1;i<total;i++)
            res = ( res % MOD + DP(i) % MOD * DP(total - i) % MOD )% MOD;
      return memo[total] = res % MOD;
}

int main(){
      int n;
      scanf("%d",&n);
      for(int i=0;i<=n+1;i++)
            memo[i]=-1;
      printf("%lld\n",DP(n+1));
      return 0;
}
