#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct water
{
    int id,t;
};
bool cmp(water a,water b);
int main(){
    int n;
    cin>>n;
    water a[1010];
    for(int i=1 ; i<=n ;i++){
        cin>>a[i].t;
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    int t_t=0;
    for(int i=1 ; i<=n ;i++){
        t_t+=a[i].t*(n-i);
        cout<<a[i].id<<" ";
    }
    cout<<endl;
    double ans=1.0*t_t/n;
    printf("%.2f",ans);
    return 0;
}
bool cmp(water a,water b){
    if(a.t!=b.t) return a.t<b.t;
    return a.id<b.id;
}

