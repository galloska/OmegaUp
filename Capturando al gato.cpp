#include <stdio.h>
#include <map>
#define lli long long int

using namespace std;

const int MAXN = 2*5005;
const int LOGMAXN = 15;

int n;
lli total;
lli num[MAXN];
int parent[MAXN];
int P[MAXN][LOGMAXN];

int logarithm(int v){
    for(int i = 0; true; i++)
        if(v <= 1 << i) return i;
}

bool possible(){
    int log = logarithm(2*n);

    for(int i = 0; i <= 2*n; i++)
        P[i][0] = parent[i];

    for(int j = 1; j <= log; j++)
        for(int i = 0; i <= 2*n; i++)
            P[i][j] = P[P[i][j - 1]][j - 1];


    for(int i=n;i<=2*n;i++){
        int v = i , goal = i - n;
        int nivel = log;
        while( P[v][nivel]!=v && v!=goal ){
            v =P[v][nivel];
            nivel--;
        }
        if(v==goal) return true;
    }
    return false;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&num[i]);
        num[i+n] = num[i];
        total += num[i];
    }

    for(int i=n-1;i>=0;i--){

        if(total%(i+1)) continue;

        lli sum = total / (i+1);
        lli aux = 0;
        int ini = 0;

        for(int j=0;j<2*n;j++) parent[j] = j;

        for(int j=0;j<2*n;j++){
            aux += num[j];
            if(aux==sum) parent[j+1] = ini;
            while(aux>sum) aux -= num[ini++];
            if(aux==sum) parent[j+1] = ini;
        }

        /*printf("Suma = %d\n",sum);
        for(int j=0;j<2*n;j++){
            printf("%d -> %d\n",j,parent[j]);
        }
        getchar();getchar();getchar();*/
        
        if(possible()){
            printf("%d\n",i+1);
            return 0;
        }
    }
    return 0;
}
