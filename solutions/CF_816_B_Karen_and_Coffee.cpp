#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>

using namespace std;
using ll = long long;

const int N = 2e5+9;
int d[N],t[N],pre[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,k,q; cin>>n>>k>>q;

    for(int i=0 ; i<n ; i++){
        int l,r; cin>>l>>r;
        d[l]++;
        d[r+1]--;
    }

    for(int i=1 ; i<=N ; i++) t[i]+=t[i-1]+d[i];

    for(int i=1 ; i<=N ; i++){
        if(t[i]>=k) pre[i]=pre[i-1]+1;
        else pre[i]=pre[i-1];
    }

    for(int i=0 ; i<q ; i++){
        int a,b; cin>>a>>b;
        cout<<pre[b]-pre[a-1]<<'\n';
    }
    

    return 0;
}