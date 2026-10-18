#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 2e6+9;
ll a[N],q[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n,m; cin>>n>>m;
    for(int i=1 ; i<=n ; i++) cin>>a[i];

    int head=1,tail=0;
    for(int i=1 ; i<=n ; i++){
        while(head<=tail && q[head]<i-m) head++;
        while(head<=tail && a[q[tail]]>a[i]) tail--;
        cout<<a[q[head]]<<'\n';
        q[++tail]=i;
    }
    
    return 0;
}