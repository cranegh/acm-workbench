#include<iostream>
using namespace std;
int main(){
    int n,m,a[1010][1010]={0};
    cin>>n>>m;
    for (int i = 1 ; i<=m ;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        for (int x=x1 ; x<=x2 ; x++){
            for (int y=y1 ; y<=y2 ; y++){
                a[x][y]++;
            }
        }
    }
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=n ; j++){
            cout<<a[i][j]<<((j<n) ? " " : "\n");
        }
    }
    return 0;
}