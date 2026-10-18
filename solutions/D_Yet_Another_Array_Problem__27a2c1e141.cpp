#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int prime[16]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

void solve()
{
    int n; cin>>n;
    vector<ll> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];
    bool ok = false;

    vector<int> ans;

    for(int i=0 ; i<n ; i++){
        ll cur = a[i];
        int j = 0;

        for(j=0 ; j<16 ; j++){
            if(cur%prime[j]!=0){
                ok = true;
                ans.push_back(prime[j]);
                break;
            }
        }
    }

    sort(ans.begin(),ans.end());
    if(ok) cout<<ans[0]<<'\n';
    else if(!ok) cout<<-1<<'\n';
    
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}