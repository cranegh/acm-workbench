#include<iostream>
#include<algorithm>
struct coin{
    int m,v;
}a[110];
bool cmp(coin x, coin y);
using namespace std;
int main(){
    int n,t,c;
    cin>>n>>t;
    for (int i=0 ; i<n ; i++){
        cin>>a[i].m>>a[i].v;
    }
    sort(a,a+n,cmp);
    double ans=0;
    c=t;
    int i;
    for ( i=0 ; i<n ; i++){
        if (c<a[i].m) break;
        c-=a[i].m;
        ans+=a[i].v;
    }
    if ( i<n ){
        ans+=1.0*c*a[i].v/a[i].m;
    }
    printf("%.2f",ans);
    return 0;
}
bool cmp(coin x, coin y){
    return x.v*y.m>y.v*x.m;
}