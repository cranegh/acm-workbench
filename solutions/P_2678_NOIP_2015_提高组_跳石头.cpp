#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

int l,n,m; 
const int N = 5e5+9;
int d[N],temp[N];

bool check(int ans)
{
    int cnt=0;
    for(int i=1 ; i<=n+1 ; i++) d[i]=temp[i];
    for(int i=1 ; i<=n+1 ; i++){
        if(d[i]<ans){
            cnt++;
            d[i+1]+=d[i];
        }
    }
    if(cnt<=m) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>l>>n>>m;
    for(int i=1 ; i<=n ; i++) cin>>d[i];
    
    d[n+1]=l-d[n];
    for(int i=n ; i>=1 ; i--) d[i]=d[i]-d[i-1];
    for(int i=1 ; i<=n+1 ; i++) temp[i]=d[i];

    int l=0,r=1e9;
    while(l+1!=r){
        int mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }

    cout<<l;

    return 0;
}