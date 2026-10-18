#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

const int N = 2e1+9;
struct p{
    int id;
    string num;
    bool operator < (const p &u) const{
        if(u.num.length()==num.length()) return num<u.num;
        else return num.length()<u.num.length();
    }
}a[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for (int i=1 ; i<=n ; i++){
        cin>>a[i].num;
    }
    for (int i=1 ; i<=n ; i++){
        a[i].id=i;
    }

    sort(a+1,a+1+n);
    reverse(a+1,a+1+n);
    cout<<a[1].id<<'\n';
    cout<<a[1].num<<'\n';

    return 0;
}
