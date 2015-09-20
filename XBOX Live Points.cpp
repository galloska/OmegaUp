#include<bits/stdc++.h>
using namespace std;
int BIT[3234342];
int N;

int kadane(int a[], int n){
    int maximo = a[0];
    int actual = a[0];
    for(int i = 1; i <n ; i++){
        actual = max(a[i],actual+a[i]);
        maximo = max (actual,maximo);
    }
    return maximo;
 }
int main(){
       cin >>  N;
       for(int i = 0; i < N; i++){
            cin >>BIT[i];
       }
       cout << kadane(BIT, N)<<endl;
}
