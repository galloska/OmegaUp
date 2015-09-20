#include <stdio.h>
#define MOD 1000000007

using namespace std;

int n;
int memo[1000005][4][4];

int main(){
      scanf("%d",&n);
      for(int j=0;j<2;j++)
            for(int h=0;h<2;h++)
                  memo[n][j][h] = 1;
      for(int id=n-1;id>=0;id--){
            for(int prev=1;prev>=0;prev--){
                  for(int ini=1;ini>=0;ini--){
                        if(id==0) memo[id][prev][ini] = ( memo[id+1][0][0] % MOD + memo[id+1][1][1] % MOD ) % MOD;
                        else if(prev==0 || (id==n-1 && ini==0)) memo[id][prev][ini] = memo[id+1][1][ini] % MOD;
                        else memo[id][prev][ini] = ( memo[id+1][0][ini] % MOD + memo[id+1][1][ini] % MOD )  % MOD;
                  }
            }
      }
      printf("%d\n",memo[0][0][0]);
      return 0;
}
