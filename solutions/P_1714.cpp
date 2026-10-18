#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 5e5+9;
ll p[N],q[N],prefix[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n,m; cin>>n>>m;
    for(int i=1 ; i<=n ; i++) cin>>p[i];
    for(int i=1 ; i<=n ; i++) prefix[i]=prefix[i-1]+p[i];

    ll ans=-1e18;
    int head=1,tail=0;
    q[++tail]=0;
    for(int i=1 ; i<=n ; i++){
        while(head<=tail && q[head]<i-m) head++;
        ans=max(ans,prefix[i]-prefix[q[head]]);
        while(head<=tail && prefix[q[tail]]>prefix[i]) tail--;
        q[++tail]=i;
    
    }

    cout<<ans;
    
    return 0;
}