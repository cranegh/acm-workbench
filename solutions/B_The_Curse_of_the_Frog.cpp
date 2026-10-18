#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 1e5+9;

struct jump{
    ll a,b,c;
}j[N];


void solve()
{
    bool reach = false;

    ll n,x; cin>>n>>x;
    ll p_s=0;
    for(int i=1 ; i<=n ; i++){
    cin>>j[i].a>>j[i].b>>j[i].c;
    p_s+=(j[i].b-1)*j[i].a;
    }

    ll ans=1e18;
    if(p_s>=x) cout<<0<<'\n';
    else{
        x-=p_s;
        ll temp=x;

        for(int i=1 ; i<=n ; i++){
            x=temp;
                if(j[i].a-j[i].c>=x){
                    cout<<1<<'\n';
                    return;
                }
                else{
                if(j[i].a*j[i].b-j[i].c<=0 ) continue;
                reach = true;
                ll cur_ans=x/(j[i].a*j[i].b-j[i].c);
                if(x%(j[i].a*j[i].b-j[i].c)!=0) cur_ans++;
                ans=min(ans,cur_ans);
                }
            }

        if(reach) cout<<ans<<'\n';
        else cout<<-1<<'\n';
        return;

    }

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}