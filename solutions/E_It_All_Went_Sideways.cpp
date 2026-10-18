#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];

    
    vector<int> pre_less(n,-1); vector<int> stk(n+1,0);
    int top=0;
    
    for(int i=n-1 ; i>=0 ; i--){
        while(top>0 && a[i]<a[stk[top]]){
            pre_less[stk[top]]=i;
            top--;
        }
        stk[++top]=i;
    }
    
    int mn=a[n-1];
    ll sum=0;

    int mx=n-1-pre_less[n-1]-1;

    for(int i=n-2 ; i>=0 ; i--){
        int cur=a[i];

        if(cur<mn){
            mn=cur;
            mx=max(mx,i-pre_less[i]-1);
        }
        sum+=(ll)cur-mn;
    }

    sum+=(ll)mx;

    cout<<sum;
    
    cout<<'\n';
    return;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    for(int i=1 ; i<=_ ; i++){
        solve();
    }

    return 0;
}