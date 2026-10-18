#include<iostream>

using namespace std;
using ll = long long;

const int N = 1e5+9;
ll a[N],t1[N],t2[N];
int n,m; 

int lowbit(int x){
    return x&-x;
}

void update(int x, ll v){
    for(int i=x ; i<=n ; i+=lowbit(i)) t1[i]+=v,t2[i]+=x*v;
}

ll getsum(int x){
    ll res=0;
    for(int i=x ; i>0 ; i-=lowbit(i)) res+=(x+1)*t1[i]-t2[i];
    return res;
}

int main(){
    cin>>n>>m;
    for(int i=1 ; i<=n ; i++) cin>>a[i];

    for(int i=1 ; i<=n ; i++) update(i,a[i]),update(i+1,-a[i]);

    while(m--){
    int op;cin>>op;
        if(op==1){
            ll l,r,v; cin>>l>>r>>v;
            update(l,v),update(r+1,-v);
        }else{
            int l,r; cin>>l>>r;
            cout<<getsum(r)-getsum(l-1)<<'\n';
        }
    }

    return 0;
}