#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;
using ll =long long;

const int N = 3e5+9;
int a[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,t; cin>>n>>t;
    for(int i=1 ; i<=n ; i++) cin>>a[i];

    int cl_t=0;
    int neop_t=0;
    for(int i=1 ; i<=n ; i++){
        if(neop_t<a[i] && a[i]<=t-100){
            cl_t+=100;
            neop_t=a[i]+100;
        }else if(neop_t<a[i] && a[i]>t-100){
            cl_t+=t-a[i];
            neop_t=a[i]+100;
        }
    }
    cout<<t-cl_t;
    
    return 0;
}