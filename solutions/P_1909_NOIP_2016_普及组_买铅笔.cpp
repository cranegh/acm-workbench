#include<iostream>
using namespace std;
int main(){
    int n,a,b,c,d,e,f,m1,m2,m3;
    cin>>n>>a>>b>>c>>d>>e>>f>>m1>>m2>>m3;
    m1=!(n%a)?b*n/a:b*(n/a+1);
    m2=!(n%c)?d*n/c:d*(n/c+1);
    m3=!(n%e)?f*n/e:f*(n/e+1);
    if(m1<m2) m2=m1;
    if(m2<m3) m3=m2;
    cout<<m3;
    return 0;
}