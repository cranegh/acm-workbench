#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1005;

struct aaa{
    int c,k;
    double w;

    bool operator < (const aaa& u) const
    {
        return w>u.w;
    }
}a[N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n,m; cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i].c;
    for(int i=1; i<=n; i++) cin>>a[i].k;
    
    for(int i=1; i<=n; i++) a[i].w = 100.0*a[i].c/a[i].k;
    sort(a+1,a+1+n);

    int x = m;
    double ans = 0;
    for(int i=1; i<=n; i++){
        if(m >= a[i].k){
            ans += 100.0*a[i].c;
            m -= a[i].k; 
        }else{
            if(m < a[i].k){
                ans += a[i].w*m;
                break;
            }
        }
    }
    
    cout<<fixed<<setprecision(4);
    cout<<ans<<'\n';

    return 0;
}