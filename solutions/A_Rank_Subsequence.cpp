#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n; 

struct restriction{
    int l,r;
    int u,v;
};

bool check(int m, const vector<restriction>& vv)
{
    int res = 0;
    int pos1 = 1;
    for(int i=0 ; i<n ; i++){
        if(res == m) break;
        int pos2 = m-pos1+1; 
        bool badleft = (vv[i].l<=pos1 && pos1<=vv[i].r);
        bool badright = (vv[i].u<=pos2 && pos2<=vv[i].v);
        if( !(badleft||badright) ){
            res++;
            pos1++;
        }
    }
    if(res < m) return false;
    else if(res == m) return true;
}

void solve()
{
    cin>>n;
    vector<restriction> vv(n);
    for(int i=0 ; i<n ; i++){
        cin>>vv[i].l>>vv[i].r>>vv[i].u>>vv[i].v;
    }

    int ans = n;
    for(int i=n ; i>=0 ; i--){
        int m = i;
        if(check(m,vv)){
            ans = m;
            break;
        }
    }

    cout<<ans<<'\n';

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}