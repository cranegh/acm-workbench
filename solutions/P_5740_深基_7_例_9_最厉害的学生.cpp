#include<iostream>
#include<algorithm>
using namespace std;
const int N =1e3+9;

struct student{
    string s;
    int a,b,c,t;
}a[N];
bool cmp (student &a,student &b){
    return a.t>b.t;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1 ; i<=n ; i++){
        cin>>a[i].s>>a[i].a>>a[i].b>>a[i].c;
    }
    for(int i=1 ; i<=n ; i++){
        a[i].t=a[i].a+a[i].b+a[i].c;
    }
    sort(a+1,a+1+n,cmp);

    cout<<a[1].s<<' '<<a[1].a<<' '<<a[1].b<<' '<<a[1].c<<endl;

    return 0;
}