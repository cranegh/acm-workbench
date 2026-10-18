#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
using ll = long long;

int n;

const int N = 3e5+9;
struct reindeer{
    ll w,p;
    bool operator < (const reindeer u) const{
        return p+w<u.p+u.w;
    }
}r[N];

ll prefixw[N],prefixp[N];

bool check(int mid){
    ll sumw=0,sump=0;
    sumw=prefixw[mid];
    sump=prefixp[mid];

    return sumw+sump<=prefixp[n];
}

void solve()
{
    cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>r[i].w>>r[i].p;

    sort(r+1,r+1+n);

    for(int i=1 ; i<=n ; i++) prefixw[i]=prefixw[i-1]+r[i].w;
    for(int i=1 ; i<=n ; i++) prefixp[i]=prefixp[i-1]+r[i].p;

    int left=0,right=n+1;
    while(left+1!=right){
        int mid=(left+right)/2;
        if(check(mid)) left=mid;
        else right=mid;
    }

    cout<<left<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}