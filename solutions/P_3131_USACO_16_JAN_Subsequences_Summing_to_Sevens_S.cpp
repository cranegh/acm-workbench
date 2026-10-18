#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 5e5+9;
ll a[N],prefix[N],first[7];

int main(){
    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>a[i];

    for(int i=1 ; i<=n ; i++) prefix[i]=prefix[i-1]+a[i];

    ll cnt=0,ans=0;
    memset(first,-1,sizeof(first));

    for(int i=1 ; i<=n ; i++){
        if(first[prefix[i]%7]==-1) first[prefix[i]%7]=i;
        ans=max(ans,i-first[prefix[i]%7]);

    }

    cout<<ans;
}