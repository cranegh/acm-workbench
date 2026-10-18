#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 1e5+9;

int n,r,q;

struct student{
    int id;
    int s,w;
    bool operator <(const student& u) const{
        if(s==u.s) return id<u.id;
        else return s>u.s;
    }
}a[2*N],win[N],lose[N];

void merge();

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>r>>q;
    for(int i=1 ; i<=2*n ; i++) cin>>a[i].s;
    for(int i=1 ; i<=2*n ; i++) cin>>a[i].w;
    for(int i=1 ; i<=2*n ;i++) a[i].id=i;

    sort(a+1,a+2*n+1);

    for(int l=1 ; l<=r ; l++)
    {
        for(int i=1 ; i<=n ; i++){
            if(a[2*i-1].w>a[2*i].w){
            a[2*i-1].s++;
            win[i]=a[2*i-1];
            lose[i]=a[2*i];
            }
            else{
            a[2*i].s++;
            win[i]=a[2*i];
            lose[i]=a[2*i-1];
            }
        }
        merge();
    }
    
    sort(a+1,a+2*n+1);
    cout<<a[q].id;

    return 0;
}

void merge()
{
    int i=1,j=1,idx=1;
    while(i<=n && j<=n){
        if(win[i]<lose[j]) a[idx++]=win[i++];
        else a[idx++]=lose[j++];
    }
    while(i<=n) a[idx++]=win[i++];
    while(j<=n) a[idx++]=lose[j++];
}