#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4194310;

int memo[MAXN];
int mat[25][25];

int main(){

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&mat[i][j]);

    for(int mask=(1<<n)-2;mask>=0;mask--){

        int res = -1<<30 , fila = 0;

        for(int i=0;i<n;i++)
            if( mask & (1<<i) )
                fila++;

        for(int i=0;i<n;i++)
            if( !( mask & (1<<i) ) )
                res = max( res , memo[ mask | (1<<i) ] + mat[fila][i] );

        memo[mask] = res;
    }

    printf("%d\n",memo[0]);
    return 0;
}
