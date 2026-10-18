#include<iostream>
#include<cmath>

using namespace std;
using ll = long long;

int n;

void solve(int n)
{
    for(int i=14 ; i>=0 ; i--){
        if(n>>i){
            if(i==0) cout<<"2(0)";
            else if(i==1) cout<<"2";
            else{
                cout<<"2(";
                solve(i);
                cout<<")";
            }
            if(n-=1<<i) cout<<"+";
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;
    solve(n);

    return 0;
}

