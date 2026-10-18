#include<bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> g[110];

struct point{
    int x,y;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    point xmnp,ymnp;

    int xmn = n;
    int ymn = n;

    for(int i=0 ; i<n ; i++){
        int xx,yy; cin>>xx>>yy;
         
        if(xx < xmn || (xx==xmn && yy<xmnp.y)){
            xmn = xmn;
        }
    }
    
    return 0;
}