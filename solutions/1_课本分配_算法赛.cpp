#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 1e5+9;
int v[N],s[N];

int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n,m; cin>>n>>m;

  for(int i=1 ; i<=n ; i++) cin>>v[i];
  for(int i=1 ; i<=m ; i++) cin>>s[i];

  sort(v+1,v+1+n);

  sort(s+1,s+1+m);

  ll cnt=0;
  for(int i=m,j=n ; i>=1 && j>=1 ; i--){
    while(v[j]>s[i] && j>1) j--;
    if(v[j]<=s[i]){
        cnt+=v[j];
        j--;
    }
  }

  cout<<cnt;

  return 0;
}