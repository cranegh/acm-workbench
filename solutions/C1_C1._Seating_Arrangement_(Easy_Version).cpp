#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n,x,m; cin>>n>>x>>m;
    string s; cin>>s;
    
    ll curx=0,curm=0;
    ll cnta=0;

    for(int i=0 ; i<n ; i++)
    {
        if(curm>=1ll*x*m) break; 
        if(s[i]=='E')
        {
            if(curm<curx*m) curm++;
            else if(cnta>0 && curx<x){
                curx++;
                curm++;
                cnta--;
            }
        }else if(s[i]=='A'){
            curm++;
            cnta++;
            if(curm>curx*m){
                curx++;
                cnta--;
            }
        }else{
            if(curx<x){
                curx++;
                curm++;
            }
        }
    }

    cout<<curm<<'\n';
    
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

    return 0;
}