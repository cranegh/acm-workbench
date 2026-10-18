#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n,m; 

int cal(vector<int>a, vector<int>&b)
{
    int ans = 0;
    for(int i=0 ; i<n-1 ; i++){
        if((a[i]+a[i+1])%m!=b[i]){
            a[i+1] = 1 - a[i+1];
            ans++;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(n-1);
    for(int i=0 ; i<n ; i++) cin>>a[i];
    for(int i=0 ; i<n-1 ; i++) cin>>b[i];

    int ans1 = cal(a,b);
    a[0] = 1 - a[0];
    int ans2 = cal(a,b)+1;
    
    int ans = min(ans1,ans2);

    cout<<ans<<'\n';
    
    return 0;
}