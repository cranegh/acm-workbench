#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll tr[N<<2];

ll m,D;
ll t = 0;
ll len = 0;

void pushup(int u){
    tr[u] = max(tr[u<<1],tr[u<<1|1]);
}

void update(int u, int l, int r, int pos, ll val){
    if(l == r){
        tr[u] = val;
        return;
    }

    int mid = (l+r)>>1;
    if(mid >= pos)
        update(u<<1,l,mid,pos,val);
    else
        update(u<<1|1,mid+1,r,pos,val);

    pushup(u);
}

ll query(int u, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return tr[u];
    }

    ll res = -INF;
    int mid = (l+r)>>1;
    if(mid >= ql)
        res = max(res,query(u<<1,l,mid,ql,qr));
    if(mid < qr)
        res = max(res,query(u<<1|1,mid+1,r,ql,qr));
    
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>m>>D;

    for(int i=0; i<m; i++){
        char ch; cin>>ch;
        if(ch == 'Q'){
            ll l; cin>>l;
            t = query(1,1,N-5,len-l+1,len);
            cout<<t<<'\n';
        }else{
            ll n; cin>>n;
            ll cur = (n+t+D)%D;

            len++;
            update(1,1,N-5,len,cur);
        }
    }

}