#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

const int N = 110;
int d[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1 ; i<=n+1 ; i++) cin>>d[i];

    bool py=0;
    for(int i=1 ; i<=n-1 ; i++){
        if(d[i]){
            if(d[i]>0 && py) cout<<"+"; 
            if(d[i]!=1 && d[i]!=-1){
                cout<<d[i]<<"x^"<<n-i+1;
                py=1;
            }
            else if(d[i]==1){
                cout<<"x^"<<n-i+1;
                py=1;
            }
            else if(d[i]==-1){
                cout<<"-x^"<<n-i+1;
                py=1;
            }
        }
    }

    if(d[n]){
            if(d[n]>0 && py) cout<<"+"; 
            if(d[n]!=1 && d[n]!=-1){
                cout<<d[n]<<"x";
                py=1;
            }
            else if(d[n]==1){
                cout<<"x";
                py=1;
            }
            else if(d[n]==-1){
                cout<<"-x";
                py=1;
            }
        }

    if(d[n+1]){
        if(d[n+1]>0 && py) cout<<"+";
        cout<<d[n+1];
    }

    return 0;
}