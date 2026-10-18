#include<iostream>
#include<cmath>

using namespace std;

const int N = 2e5+9;

struct pai{
    int num;
    char c;
    int idx;
    bool operator < (const pai& u) const{
        return num<u.num;
    }
}p[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>p[i].num>>p[i].c;
    for(int i=1 ; i<=n ; i++) p[i].idx=i;

    sort(p+1,p+1+n);

    return 0;
}