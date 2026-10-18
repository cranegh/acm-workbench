#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>

using namespace std;
using ll = long long; 

void solve()
{
    int n,k; cin>>n>>k;

    int t=0;

    if(n==k){
        cout<<t<<'\n';
        return;
    }

    while(n>0){
        t++;
        int a=n/2,b=n-n/2;
        
        if(b<k){
            cout<<-1<<'\n';
            return;
        }

        if(a==k || b==k){
            cout<<t<<'\n';
            return;
        }

        if(a%2==1) n=a;
        else n=b;
    }

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}