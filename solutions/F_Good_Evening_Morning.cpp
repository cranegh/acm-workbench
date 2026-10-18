#include<bits/stdc++.h>

using namespace std;
using ll = long long;

bool check(int a, int e)
{
    if(6<=a && a<=17 && !(6<=e && e<=17)) return true;
    else return false;

}

void solve()
{
    int d,t; cin>>d>>t;
    int a = t;
    int e = (t+d)%24;

    int tt = 0;
    int ans = -1;
    for( ; tt<24 ; tt++){
        int aa = (a+tt)%24;
        int ee = (e+tt)%24;
        //cout<<e<<' ';
        if(check(aa,ee)){
            ans = tt;
            break;
        }
    }

    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();
    
    return 0;
}