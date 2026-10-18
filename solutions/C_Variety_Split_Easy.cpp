#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<string>
#include<bitset>
#include<stack>

using namespace std;
using ll = long long;

const int N = 3e5+9;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll cntl[N];
ll cntr[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;

    vector<int> v(n+1);
    for(int i=1 ; i<=n ; i++) cin>>v[i];

    cntl[v[1]]++;
    ll sum=1;
    for(int i=2 ; i<=n ; i++) if(!cntr[v[i]]++) sum++;

    ll ans=sum;
    for(int i=2 ; i<n ; i++){
        if(!cntl[v[i]]++) sum++;
        if(!--cntr[v[i]]) sum--;

        ans=max(sum,ans);
    }

    cout<<ans;

    return 0;
}