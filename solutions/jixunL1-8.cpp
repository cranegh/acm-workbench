#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 1e6+9;

ll grid[1010][1010];

struct building {
    ll val;
    int x,y;
};

bool cmp(building &a , building &b){
    return a.val>b.val;
}

bool h[N];
bool l[N];

vector<building> b;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m,k; cin>>n>>m>>k;

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            cin>>grid[i][j];
            b.push_back({grid[i][j],i,j});
        }
    }

    for(int i=1 ; i<=n ; i++) h[i]=true;
    for(int i=1 ; i<=m ; i++) l[i]=true;

    sort(b.begin(),b.end(),cmp);

    int cnt=0;
    for(int i=0 ; i<k ; i++){
        while( !h[b[cnt].x] || !l[b[cnt].y] ) cnt++;

        h[b[cnt].x]=false;
        l[b[cnt].y]=false;
        cnt++;

    }

    for(int i=1 ; i<=n ; i++){

        if(!h[i]) continue;

        bool notfirst = false;
        for(int j=1 ; j<=m ; j++){

            if(!l[j]) continue;

            if(notfirst) cout<<' ';
            
            cout<<grid[i][j];
            notfirst = true;

        }
        cout<<'\n';
    }

    return 0;
}