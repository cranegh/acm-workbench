#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

ll qpow(ll a , ll n){
    ll res=1;
    while(n>0){
        if(n%2==1) res*=a;
        n/=2;
        a*=a;
    }
    return res;
}

ll f(int k){
    return (qpow(4,k)-1)/3; 
}

bool check(int mid, int a, int b){
    int ji=(mid+1)/2;
    int ou=mid/2;

    ll cost_ji=f(ji);
    ll cost_ou=2*f(ou);

    if(a>=cost_ji && b>=cost_ou) return true;
    if(b>=cost_ji && a>=cost_ou) return true;

    return false;
}

void solve()
{
    int a,b; cin>>a>>b;
    
    int l=0, r=22;
    while(l+1!=r){
        int mid=(l+r)/2;
        if(check(mid,a,b)) l=mid;
        else r=mid; 
    }
    cout<<l<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}