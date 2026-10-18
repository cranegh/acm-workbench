#include<iostream>

using namespace std;

const int N = 21;
int n,k;
int a[N];

int cnt=0;
bool check(int x){
    if(x==1) return false;
    for(int i=2 ; i*i<=x ; i++){
        if(x%i==0){
            return false;
            break;
        }
    }
    return true;
}

void dfs(int x, int y, int z){
    if(y+n-x+1<k) return;

    if(y==k){
        if(check(z)) cnt++;
        return ;
    }

    dfs(x+1,y+1,z+a[x]);

    dfs(x+1,y,z);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>k;
    for(int i=1 ; i<=n ; i++) cin>>a[i];

    dfs(1,0,0);

    cout<<cnt;

}