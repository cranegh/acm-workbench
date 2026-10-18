#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 3e5+9;
const int MOD = 998244353;

int n,k;
ll sum=0;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>k;
    vector<pair<int,int>> v(n);

    for(int i=0 ; i<n ; i++)
    {
        int a,b; cin>>a>>b;
        sum+=b;
        v[i]={a,b};
    }

    sort(v.begin(),v.end());

    int day=1;
    for(int i=0 ; i<=n ; i++){
        if(sum<=k){
            cout<<day;
            break;
        }
        day=v[i].first+1;
        sum-=v[i].second;
    }
    
    return 0;
}