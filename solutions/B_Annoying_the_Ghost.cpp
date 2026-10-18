#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);

    for(int i=0 ; i<n ; i++) cin>>a[i];
    for(int i=0 ; i<n ; i++) cin>>b[i];

    vector<int> p(n,-1);
    vector<bool> used(n,false);

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(!used[j] && b[j]>=a[i]){
                p[i] = j;
                used[j] = true;
                break;
            }
        }
    }

    bool pp = true;
    for(int i=0 ; i<n ; i++)
        if(p[i]==-1)
            pp = false;

    if(!pp) cout<<-1<<'\n';
    else
    {
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                if(p[j]<p[i]) ans++;
            }
        }
        cout<<ans<<'\n';
    }


    return;

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}