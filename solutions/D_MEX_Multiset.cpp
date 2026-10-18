#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    int cnt0 = 0;
    for(int &x : a){
        if(x == 0) cnt0++;
    }

    if(cnt0 == 0){
        cout<<"YES\n";
        cout<<"AB";
        for(int i=0; i<n-2; i++) cout<<"C";
        cout<<'\n';
    }else if(cnt0 == 1){
        cout<<"NO\n";
    }else if(cnt0 >= 2){
        bool hadA = false;
        cout<<"YES\n";
        for(int &x : a){
            if(x==0){
                if(hadA) cout<<'B';
                else cout<<'A';
                hadA = true;
            }else{
                cout<<'C';
            }
        }
        cout<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}