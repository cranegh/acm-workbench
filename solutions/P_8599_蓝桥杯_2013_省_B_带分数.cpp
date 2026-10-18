#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<bitset>
#include<queue>

using namespace std;
using ll = long long;

bool vis[15];

int n;
ll ans=0;

bool check(int a, int c){
    ll b = 1ll*c*(n-a);
    if(b<=0) return false;

    bool temp_vis[15];
    for(int i=1 ; i<=9 ; i++) temp_vis[i]=vis[i];

    while(b>0){
        int digit=b%10;
        if(digit==0 || temp_vis[digit]) return false;
        temp_vis[digit]=true;
        b/=10;
    }

    for(int i=1 ; i<=9 ; i++){
        if(!temp_vis[i]) return false;
    }

    return true;
}

void dfs_c(int a, int c){
    if(c>0 && check(a,c)) ans++;

    for(int i=1 ; i<=9 ; i++){
        if(!vis[i]){
            vis[i]=true;
            dfs_c(a,c*10+i);\
            vis[i]=false;
        }
    }
}

void dfs_a(int a){
    if(a>=n) return;

    if(a>0){
        dfs_c(a,0);
    }

    for(int i=1 ; i<=9 ; i++){
        if(!vis[i]){
            vis[i]=true;
            dfs_a(a*10+i);
            vis[i]=false;
        }
    }


}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;
    dfs_a(0);

    cout<<ans;

    return 0;
}