#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n,k; cin>>n>>k;
    vector<int> a(n); for(int i=0 ; i<n ; i++) cin>>a[i];
    vector<int> cnt(n+1,0); for(int i=0 ; i<n ; i++) cnt[a[i]]++;
    vector<int> req(n+1,0);

    bool pp = true;
    for(int i=0 ; i<n ; i++){
        int cur = cnt[a[i]]%k;
        if(cur!=0) pp = false;
        
        int ccr = cnt[a[i]]/k;
        req[a[i]] = ccr;
    }

    if(!pp){
        cout<<0<<'\n';
        return;
    }

    ll ans = 0;
    vector<int> had(n+1,0);
    int head = 0, tail = 0;
    
    for(tail = 0; tail<n ; tail++){
        had[a[tail]]++;

        while(had[a[tail]]>req[a[tail]]){
            had[a[head]]--;
            head++;
        }

        ans += tail-head+1;
    }

    cout<<ans<<'\n';

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}