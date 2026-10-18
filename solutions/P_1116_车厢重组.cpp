#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

const int N = 1e5+9;
ll h[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,b; cin>>n>>b;
    for (int i=1 ; i<=n ; i++){
        cin>>h[i];
    }
    
    sort(h+1,h+1+n);
    reverse(h+1,h+1+n);

    int num=0,H=0;
    for(int i=1 ; i<=n ; i++){
        num++;
        H+=h[i];
        if (H>=b) break;
    }

    cout<<num<<'\n';
    
    return 0;
}
