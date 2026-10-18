#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
    while(b!=0)
    {
        ll tmp=a%b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=0 ; i<n ; i++)
    {
        ll ans=0;
        ll a0,a1,b0,b1; cin>>a0>>a1>>b0>>b1;
        for(ll x=1 ; x*x<=b1 ; x++){
            if(b1%x==0){
            
                if(x%a1==0){
                    ll f1=x/a1; ll f2=a0/a1; ll f3=b1/b0; ll f4=b1/x;
                    if(gcd(f1,f2)==1 && gcd(f3,f4)==1) ans++;
                }

                ll y = b1/x;
                if(x==y) continue;

                if(y%a1==0){
                    ll ff1=y/a1; ll ff2=a0/a1; ll ff3=b1/b0; ll ff4=b1/y;
                    if(gcd(ff1,ff2)==1 && gcd(ff3,ff4)==1) ans++;
                }
            }
            
        }
        cout<<ans<<'\n';
    }

    return 0;
}