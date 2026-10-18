#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct w{
    ll x,y;
};

bool cmp(w a, w b){
    if(a.x == b.x) a.y<b.y;
    return a.x<b.x;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    vector<w> v(n);
    for(int i=0; i<n ; i++) cin>>v[i].x>>v[i].y;

    sort(v.begin(),v.end(),cmp);

    return 0;
} 