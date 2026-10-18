#include<iostream>
#include<algorithm>
using namespace std;
const int N = 5e2+9;
struct team
{
    int x,y;
    bool operator<(const team& u)const{
        if(x==u.x) return y>u.y;
        else return x<u.x;
    }
    bool operator==(const team& u)const{
        bool p=(x==u.x && y==u.y);
        return p;
    }
}a[N];


int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;

    for(int i=1 ; i<=n ; i++){
        cin>>a[i].x>>a[i].y;
    }
    
    team c=a[1];

    sort(a+1,a+n+1);
    reverse(a+1,a+1+n);

    if(a[n/10]<c || a[n/10]==c) cout<<"gold";
    else if (a[n/10*2]<c || a[n/10*2]==c) cout<<"silver";
    else if (a[n/10*3]<c || a[n/10*3]==c) cout<<"bronze";
    else cout<<"iron";

    return 0;
    

}
