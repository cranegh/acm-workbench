#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n;
const int N = 12;
int s[N],b[N];

int ts=1,tb=0;
int ans=1e9;
void dfs(int dep){
    if(dep>n){
        if(tb>0) ans=min(ans,abs(ts-tb));
        return;
    }


    ts*=s[dep];
    tb+=b[dep];
    dfs(dep+1);
    ts/=s[dep];
    tb-=b[dep];

    dfs(dep+1);
    

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>s[i]>>b[i];

    dfs(1);

    cout<<ans;

    return 0;
}