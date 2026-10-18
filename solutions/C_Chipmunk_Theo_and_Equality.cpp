#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void cal(ll base, unordered_map<ll,int>& cnt, unordered_map<ll,int>& cc, vector<ll>& path)
{
    ll res=0;
    if(cc.count(base)!=0) cc[base]++;

    if(base==1){
        cc[2]++;
        cnt[2]+=1;
        return;
    }

    while(1){
        if(base%2==0){
            base/=2;
            if(cc.count(base)!=0) cc[base]++;
            res++;
            //cout<<base<<" "<<res<<'\n';
            if(cc.count(base)!=0) cnt[base]+=res;
            //cout<<cnt[base]<<'\n';
            if(base==1) break;
        }else if(base%2==1){
            base+=1;
            if(cc.count(base)!=0) cc[base]++;
            res++;
            //cout<<base<<" "<<res<<'\n';
            if(cc.count(base)!=0) cnt[base]+=res;
            //cout<<cnt[base]<<'\n';
            if(base==1) break;
        }
    }
    //cout<<"cnt[1]:";
    //cout<<cnt[1]<<'\n';
}

void solve()
{
    unordered_map<ll,int> cnt;
    unordered_map<ll,int> cc;
    vector<ll> path;

    int n; cin>>n;
    vector<ll> a(n); for(int i=0 ; i<n ; i++) cin>>a[i];

    ll tt = a[0];

    ll res=0;
    cc[tt]++;
    path.push_back(tt);
    if(tt==1){
        path.push_back(2);
        cc[2]++;
        cnt[2]+=1;
    }else{
        while(1){
            if(tt%2==0){
                tt/=2;
                path.push_back(tt);
                cc[tt]++;
                res++;
                cnt[tt]+=res;
                if(tt==1) break;
            }else if(tt%2==1){
                tt+=1;
                path.push_back(tt);
                cc[tt]++;
                res++;
                cnt[tt]+=res;
                if(tt==1) break;
            }
        }
    }

    for(int i=1 ; i<n ; i++){
        cal(a[i],cnt,cc,path);
    }

    ll ans = 1e18;
    for(auto it = path.begin() ; it!=path.end() ; it++){
        //if(cc[*it]==n) cout<<*it<<' ';
        if(cc[*it]==n && cnt[*it]<ans) ans=cnt[*it];
    }

    cout<<ans<<'\n';


}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

    return 0;
}