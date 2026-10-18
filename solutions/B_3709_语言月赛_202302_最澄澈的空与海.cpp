#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;
using ll =long long;

ll f(int x){
    ll res=1;
    while(x>=1){
        res*=x;
        x-=1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    int z=2;
    int x=2*(f(n)-n),y=2*(f(n)-2*n);

    cout<<x<<' '<<y<<' '<<z;

    
    return 0;
}