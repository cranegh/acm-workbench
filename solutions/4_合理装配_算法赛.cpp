#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 1e5+9;
int num[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int a,b; cin>>a>>b;
    if(a<b){
        int t=a;
        a=b,b=t;
    }

    int m=1e5;
    for(int i=0 ; i<=b ; i++){
        int tmp=abs(a-3*b+4*i);
        m=min(tmp,m);
    }

    cout<<m;

    return 0;
    
}