#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<ll> a(n); for(int i=0 ; i<n ; i++) cin>>a[i];
    vector<ll> aa(n); for(int i=0 ; i<n ; i++) aa[i] = a[i];

    sort(a.begin(),a.end());
    unordered_map<ll,int> cnt;
    unordered_map<ll,ll> mp;
    vector<ll> ans; ans.push_back(a[0]);

    for(int i=0 ; i<n ; i++) cnt[a[i]]++;
    for(int i=1 ; i<n ; i++){
        if(ans[ans.size()-1]!=a[i]) ans.push_back(a[i]);
    }

    if(cnt.count(0)==0){
        cout<<-1<<'\n';
        return;
    }else{
        ll tt = 0;
        ll Pre = 0;
        for(int i=1 ; i<ans.size() ; i++){
            ll cur = ans[i]-tt;
            if(cur%cnt[ans[i-1]]==0){
                if(cur/cnt[ans[i-1]]<Pre+1){
                    cout<<-1<<'\n';
                    return;
                }
                //mp[ans[i-1]] = max(cur/cnt[ans[i-1]],Pre+1);
                mp[ans[i-1]] = cur/cnt[ans[i-1]];
                Pre = mp[ans[i-1]];
                tt += cur; 
            }else{
                cout<<-1<<'\n';
                return;
            }
        }
        mp[ans[ans.size()-1]] = Pre+1;
    }

    for(int i=0 ; i<n ; i++){
        cout<<mp[aa[i]]<<" ";
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

    return 0;
}