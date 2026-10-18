#include<iostream>
#include<algorithm>

using ll = long long;
using namespace std;
const int N =1e2+9;
int a[22][22][22];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int w,x0,h; cin>>w>>x0>>h;
   
    for(int x=1 ; x<=w ; x++)
    for(int y=1 ; y<=x0 ; y++)
    for(int z=1 ; z<=h ; z++)
    a[x][y][z]=1;

    int q; cin>>q;
    while(q--){
        int x1,y1,z1,x2,y2,z2; cin>>x1>>y1>>z1>>x2>>y2>>z2;
        for(int i=x1 ; i<=x2 ; i++)
        for(int j=y1 ; j<=y2 ; j++)
        for(int k=z1 ; k<=z2 ; k++)
        a[i][j][k]=0;
    }

    int ans=0;
    for(int x=1 ; x<=w ; x++)
    for(int y=1 ; y<=x0 ; y++)
    for(int z=1 ; z<=h ; z++)
    ans+=a[x][y][z];

    cout<<ans;

    return 0;
}
