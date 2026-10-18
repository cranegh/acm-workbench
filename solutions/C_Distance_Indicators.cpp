#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;
using ll = long long;

const int N = 2e5+9;
const int M = 2*N;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll cntl[M];
ll cntr[M];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;

    for(int i=0 ; i<n ; i++){
        int cur; cin>>cur;
        int l=i-cur;
        int r=i+cur;

        if(l>=0) cntl[l]++;
        if(r>=0) cntr[r]++;
    }
    
    ll ans=0;
    for(int i=1 ; i<=N ; i++){
        ans+=cntl[i]*cntr[i];
    }

    cout<<ans;

    return 0;
}