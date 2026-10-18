#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 1e5+9;
ll a[N],q[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n,k; cin>>n>>k;
    
    for(int i=1 ; i<=n ; i++) cin>>a[i];
    int tail=0,head=1;

    for(int i=1 ; i<=n ; i++){
        while(head<=tail && i-q[head]+1>k) head++;
        while(head<=tail && a[i]<=a[q[tail]]) tail--;
        q[++tail]=i;
        if(i>=k) cout<<a[q[head]]<<' ';
    }
    cout<<'\n';

    head=1,tail=0;
    for(int i=1 ; i<=n ; i++){
        while(head<=tail && i-q[head]+1>k) head++;
        while(head<=tail && a[i]>=a[q[tail]]) tail--;
        q[++tail]=i;
        if(i>=k) cout<<a[q[head]]<<' ';
    }
    
    return 0;
    
}