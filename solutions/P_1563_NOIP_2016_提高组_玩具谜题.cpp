#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

const int N = 1e5+9;
struct p{
    int f;
    string n; 
}a[N];
int n,m; 

void cr(int &x){
    if(1<=x && x<=n) return;
    else if(x>n){
        x%=n;
        if(x==0) x=n;
    }
    else if(x<1){
        int d=1-x;
        d%=n;
        if(d==0) x=1;
        else x=n+1-d;
    }
    return;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    cin>>n>>m;
    for(int i=1 ; i<=n ; i++){
        cin>>a[i].f;
        cin>>a[i].n;
    }

    int cur=1;
    for(int i=1 ; i<=m ; i++){
        int zy,j; cin>>zy>>j;
        cr(cur);

        if(a[cur].f != zy){
            cur+j;
        }else{
            cur-j;
        }
    }

    cr(cur);

    cout<<a[cur].n;

    return 0;
}