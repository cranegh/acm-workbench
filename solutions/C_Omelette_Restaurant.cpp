#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
using ll = long long;

void solve(){
    int n,d; cin>>n>>d;
    deque< pair<int,int> > q;

    vector<int> a(n);
    vector<int> b(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];
    for(int i=0 ; i<n ; i++) cin>>b[i];

    for(int i=0 ; i<n ; i++){
        q.push_back({a[i],i});
        while(!q.empty() && q.front().first<=b[i]){
            b[i]-=q.front().first;
            q.pop_front();
        }
        if(!q.empty() && b[i]<q.front().first) q.front().first-=b[i];

        while(!q.empty() && i-q.front().second>=d) q.pop_front();
    }

    ll ans=0;
    for(auto &i : q) ans+=(ll)i.first;

    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;

}