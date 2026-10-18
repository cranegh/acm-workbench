#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n,x; ll k; cin>>n>>x>>k;
    int mid = n/2+1;
    int sz = n/2;

    deque<int> dq1;
    deque<int> dq2;

    for(int i=1; i<=sz; i++) dq1.push_back(i);
    for(int i=mid+1; i<=n; i++) dq2.push_back(i);

    k %= 2ll*n;

    int op = x;
    for(int i=1; i<=k; i++){
        if(op == 1){
            dq2.push_back(mid);
            mid = dq2.front();
            dq2.pop_front();
        }else{
            dq1.push_front(mid);
            mid = dq1.back();
            dq1.pop_back();
        }
        op ^= 1;
    }
    
    for(int i=0; i<sz; i++) cout<<dq1[i]<<" ";
    cout<<mid<<" ";
    for(int i=0; i<sz; i++) cout<<dq2[i]<<" ";
    cout<<'\n';
    
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}

