#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5+9;
bitset<N> vis;

int gcd(int da, int xiao){
    int tmp=da%xiao;
    while(tmp!=0){
        da=xiao;
        xiao=tmp;
        tmp=da%xiao;
    }
    return xiao;
}

void solve()
{
    int n; cin>>n;
    vector<int> v(n); 
    for(int i=0 ; i<n ; i++) cin>>v[i];

    int ans=0;
    for(int i=0 ; i<n-1 ; i++){
        int m=abs(v[i]-v[i+1]);
        if(gcd(v[i],v[i+1])==m) ans++;
    }

    cout<<ans;
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}