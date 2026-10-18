#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    double a,b; cin>>a>>b;
    string s="";
    int k = 0;

    while(b!=a){
        if(b>0.5){
            b-=0.5;
            b*=2;
            s += "2";
        }else if(b<=0.5){
            b*=2;
            s += "1";
        }

        k++;
        if(k==50) break;
    }

    for(int i=s.length()-1 ; i>=0 ; i--) cout<<s[i];

    return;

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}