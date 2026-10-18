#include<iostream>
#include<iomanip>

using namespace std;
using ll = long long;

double p;

double qpow(double a, int n){
    double res=1;
    while(n>=1){
        if(n%2==1){
            res*=a;
        }
        a*=a;
        n/=2;
    }
    return res;
}

double f(int x){
    return (1-qpow(1-p,x))/p-x*qpow(1-p,x);
}


int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    cin>>p;
    int l,r; cin>>l>>r;

    double ans;

    int x=0 ; int y=n;
    while(x+1!=y){
        int mid=(x+y)/2;
        if(f(mid)<l) x=mid;
        else if(f(mid)>r) y=mid;
        else if(l<=f(mid) && f(mid)<=r){
            ans=f(mid);
            break;
        }
    }

    cout<<fixed<<setprecision(6)<<ans;
    return 0;
}