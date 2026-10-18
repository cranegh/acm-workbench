#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;
using ll = long long;

double a,b,c,d;

double f(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}

double qiuf(double l ,double r)
{
    if(f(l)<f(r)){
        while((r-l)>1e-6){
            double mid=(l+r)/2;
            if(f(mid)>0) r=mid;
            else l=mid;
        }
    }
    if(f(l)>f(r)){
        while((r-l)>1e-6){
            double mid=(l+r)/2;
            if(f(mid)>0) l=mid;
            else r=mid;
        }
    }
    return l;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>a>>b>>c>>d;

    double t_mid=-b/3*a;

    double t1=(-2*b-sqrt(4*b*b-4*3*a*c))/6*a;
    double t2=(-2*b+sqrt(4*b*b-4*3*a*c))/6*a;

    double x1=qiuf(-100,t1);
    double x2=qiuf(t1,t2);
    double x3=qiuf(t2,100);

    cout<<fixed<<setprecision(2)<<x1<<' '<<x2<<' '<<x3;

    return 0;
}