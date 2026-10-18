#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

struct p{
    int id,point;
    bool operator < (const p &u) const{
        if (point==u.point) return id>u.id;
        else return point<u.point;
    }
}a[5010];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m; cin>>n>>m;
    for (int i=1 ; i<=n ; i++){
        cin>>a[i].id>>a[i].point;
    }
    
    sort(a+1,a+1+n);
    reverse(a+1,a+1+n);

    int mx=a[int(m*1.5)].point,mn=0;
    for (int i=1 ; i<=n ; i++){
        if(a[i].point>=mx) mn++;
    }

    cout<<mx<<' '<<mn<<'\n';

    for (int i=1 ; i<=mn ; i++){
        cout<<a[i].id<<' '<<a[i].point<<'\n';
    }
    
    return 0;
}
