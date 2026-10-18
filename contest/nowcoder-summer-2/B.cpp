#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    int cnt = 0;

    if(5<n && n<=600000 && (n%2)){
        for(int i=1 ; i<=300000 ; i++){
            if(cnt<n-1) cout<<i<<" ";
            cnt++;
            if(cnt<n-1) cout<<i<<" ";
            cnt++;
        }

        cout<<n/2-2<<'\n';
        return;
    }

    for(int i=1 ; i<=300000 ; i++){
        if(cnt<n) cout<<i<<" ";
        cnt++;
        if(cnt<n) cout<<i<<" ";
        cnt++;
    }

    for(int i=1 ; i<=300000 ; i+=2){
        if(cnt<n) cout<<i<<" ";
        cnt++;
    }

    for(int i=2 ; i<=300000 ; i+=2){
        if(cnt<n) cout<<i<<" ";
        cnt++;
    }

    for(int i=3 ; i<=300000 ; i+=3){
        if(cnt<n) cout<<i<<" ";
        cnt++;
    }

    cout<<'\n';
    
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1;
    cin>>T;
    
    while(T--) solve();

    return 0;
} 