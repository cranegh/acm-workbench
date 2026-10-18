#include<iostream>
#include<bitset>

using namespace std;
using ll = long long;

const int N = 55;
bool vis[N][N];

void solve()
{
    for(int i=1 ; i<N ; i++) for(int j=1 ; j<N ; j++) vis[i][j]=false;
    for(int i=11 ; i<=30 ; i++) vis[25][i]=true;

    int n; cin>>n;
    if(n==0) return;

    string s; cin>>s;
    int m=0;
    int cur_hx=25,cur_hy=30;
    int cur_tx=25,cur_ty=11;

    bool into = false;
    bool off = false;

    for(int i=0 ; i<n ; i++){
        if(s[i]=='E'){
            vis[cur_tx][cur_ty++]=false;
            if(vis[cur_hx][++cur_hy]){
                into=true;
                m++;
                break;
            }
        }else if(s[i]=='W'){
            
        }
    }


}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();
    
    return 0;
}