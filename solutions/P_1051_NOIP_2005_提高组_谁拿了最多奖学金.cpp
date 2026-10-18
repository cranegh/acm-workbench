#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 110;

struct student{
    string name;
    int p1,p2;
    char t1,t2;
    int l;
    int t_j=0;
    int id;
    bool operator <(const student& u) const{
        if(t_j==u.t_j) return id<u.id;
        else return t_j>u.t_j;
    }
}a[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1 ; i<=n ; i++)
    cin>>a[i].name>>a[i].p1>>a[i].p2>>a[i].t1>>a[i].t2>>a[i].l;
    for(int i=1 ; i<=n ;i++) a[i].id=i;

    for(int i=1 ; i<=n ; i++){
        if(a[i].p1>80 && a[i].l>=1) a[i].t_j+=8000;
        if(a[i].p1>85 && a[i].p2>80) a[i].t_j+=4000;
        if(a[i].p1>90) a[i].t_j+=2000;
        if(a[i].p1>85 && a[i].t2=='Y') a[i].t_j+=1000;
        if(a[i].p2>80 && a[i].t1=='Y') a[i].t_j+=850;
    }

    ll n_tj=0;
    for(int i=1 ; i<=n ; i++) n_tj+=a[i].t_j;

    sort(a+1,a+1+n);
    cout<<a[1].name<<'\n';
    cout<<a[1].t_j<<'\n';
    cout<<n_tj<<endl;

    return 0;
}