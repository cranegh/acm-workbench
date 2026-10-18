#include<iostream>
#include<algorithm>
using ll = long long;
using namespace std;
int isprime;
const int N =1e2+9;
int a[N];
void check(int x);

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n; cin>>n;
    for(int i=2 ; i*i<=n ; i++){
        check(i);
        if(isprime && n/i*i==n){
            check(n/i);
            if(isprime) cout<<n/i;
        }
    }

    return 0;
}
void check(int x){
    isprime=1;
    if(x==1) isprime=0;
    else{
        for(int i=2 ; i*i<=x ; i++){
            if (x%i==0){
                isprime=0;
                break;
            }
        }
    }
}
