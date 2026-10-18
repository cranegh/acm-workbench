#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstring>

using namespace std;
using ll = long long;

const int N = 110;
int a[12][12];
int check[10];

bool hegui;

void solve()
{
    hegui=true;

    for(int i=1 ; i<=9 ; i++){
        for(int j=1 ; j<=9 ; j++){
            cin>>a[i][j];
        }
    }

    for(int i=1 ; i<=7 ; i+=3){
        for(int j=1 ; j<=7 ;j+=3){
            
            for(int k=1 ; k<=9 ; k++) check[k]=0;
            
            for(int x=i ; x<=i+2 ; x++){
                for(int y=j ; y<=j+2 ; y++){
                    if(1<=a[x][y] && a[x][y]<=9){
                        check[a[x][y]]++;
                        if(check[a[x][y]]>1){
                            hegui=false;
                        }
                    }
                }
            }
        }
    }

    for(int k=1 ; k<=9 ; k++) check[k]=0;
    for(int i=1 ; i<=9 ; i++){
        for(int k=1 ; k<=9 ; k++) check[k]=0;
        for(int j=1 ; j<=9 ; j++){
            check[a[i][j]]++;
            if(check[a[i][j]]>1){
                hegui=false;
            }
        }
    }

    for(int k=1 ; k<=9 ; k++) check[k]=0;
    for(int i=1 ; i<=9 ; i++){
        for(int k=1 ; k<=9 ; k++) check[k]=0;
        for(int j=1 ; j<=9 ; j++){
            check[a[j][i]]++;
            if(check[a[j][i]]>1){
                hegui=false;
            }
        }
    }

    if(hegui) cout<<1<<'\n';
    else cout<<0<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}