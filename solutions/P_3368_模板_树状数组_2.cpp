#include<iostream>

using namespace std;
using ll = long long;

const int N = 5e5+9;
ll a[N],t[N];
int n,m; 

int lowbit(int x){
    return x&-x;
}

void update(int x, ll v){
    for(int i=x ; i<=n ; i+=lowbit(i)) t[i]+=v;
}

ll getsum(int x){
    ll res=0;
    for(int i=x ; i>0 ; i-=lowbit(i)) res+=t[i];
    return res;
}

int main(){
    cin>>n>>m;
    for(int i=1 ; i<=n ; i++) cin>>a[i];

    for(int i=1 ; i<=n ; i++) update(i,a[i]),update(i+1,-a[i]);

    while(m--){
    int op; cin>>op;
    if(op==1){
        ll l,r,k; cin>>l>>r>>k;
        update(l,k),update(r+1,-k);
    }else{
        int q; cin>>q;
        cout<<getsum(q)<<'\n';
    }
    }
    return 0;
}