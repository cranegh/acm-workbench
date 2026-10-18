#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5+9;
const int MOD = 998244353;

int n;
int cnt[N];
int ans[N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;
    vector<int> a(3*n+1);
    for(int i=1 ; i<=3*n ; i++) cin>>a[i];

    for(int i=1 ; i<=3*n ; i++){
        cnt[a[i]]++;
        if(cnt[a[i]]==2) ans[a[i]]=i;
    }

    vector<pair<int,int>> v(n);
    for(int i=0 ; i<n ; i++) v[i]={ans[i+1],i+1};

    sort(v.begin(),v.end());

    for(int i=0 ; i<n ; i++) cout<<v[i].second<<' ';
    
    return 0;
}