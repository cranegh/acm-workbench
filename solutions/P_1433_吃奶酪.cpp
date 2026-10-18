#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;

int n;
double x[20],y[20];

double dist(int a, int b){
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

bool vis[20];
double ans=1e8;
void dfs(int now , int done , double sum){
    if(sum>=ans) return;
    
    if(done==n){
        ans=min(ans,sum);
        return;
    }

    for(int i=1 ; i<=n ; i++){
        if(!vis[i]){
            vis[i]=true;
            dfs(i,done+1,sum+dist(i,now));
            vis[i]=false;
        }
    }

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>x[i]>>y[i];

    x[0]=0,y[0]=0;

    dfs(0,0,0);

    cout<<fixed<<setprecision(2)<<ans;

}