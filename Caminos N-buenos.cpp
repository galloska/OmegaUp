#include <bits/stdc++.h>
#define lli long long int
#define MOD 10000000007

using namespace std;

const int MAXN = 305;

lli mat[MAXN][MAXN];
lli memo[5][MAXN][MAXN];

int main(){

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%lld",&mat[i][j]);

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            for(int h=n;h>=0;h--){

                if(i==n-1 && i==j){
                    if( !( ( mat[i][j] + h ) % n ) )
                        memo[i&1][j][h] = 1;
                    continue;
                }

                lli res = memo[ (i + 1)&1 ][j][ (h + mat[i][j])%n ];
                res = ( res + memo[i&1][ j + 1 ][ (h + mat[i][j])%n ] )%MOD;

                memo[i&1][j][h] = res;
            }
        }
    }

    printf("%lld\n",memo[0][0][0]);

    return 0;
}
