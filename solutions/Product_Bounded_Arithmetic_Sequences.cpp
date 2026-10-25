#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll n;

bool check(ll a, ll k, ll d){
    ll res = n;
    for(ll i=1; i<=k; i++){
        res /= a+(i-1)*d;
        if(res == 0) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;

    ll ans = 0;
    for(ll a=1; a*a*a<=n; a++){
        for(ll k=3; k<=20; k++){
            ll l = 0, r = pow(1.0*n/2,1.0/2)+1;
            if(!check(a,k,1)) break;

            while(l+1!=r){
                ll d = (l+r)/2;
                
                if(check(a,k,d))
                    l = d;
                else
                    r = d;
            }

            ans += l;
        }
    }
    
    cout<<ans<<endl; 

    return 0;

}
