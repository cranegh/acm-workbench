#include<iostream>

using namespace std;

const int N = 40;
int a[N][N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    a[1][n/2+1]=1;

    for(int i=2 ; i<=n*n ; i++){
        
        int h=0,l=0;

        if(h==1){
            if(l==n) a[2][l]=i;
            else a[n][l+1]=i;
        }else{
            if(l==n) a[h-1][1]=i;
            else{
                if(a[h-1][l+1]==0) a[h-1][l+1]=i;
                else a[h+1][l]=i;
            }
        }

    }

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}