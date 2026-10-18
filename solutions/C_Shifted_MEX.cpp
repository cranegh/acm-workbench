#include<iostream>
#include<algorithm>

using namespace std;

const int N = 3e3+9; 
int a[N];

void solve()
{

    int max_l=1;
    int n; cin>>n;

    for(int i=1 ; i<=n ; i++){
        cin>>a[i];
    }

    sort(a+1,a+1+n);
    int l=1;
    for(int i=2 ; i<=n ; i++){
        if(a[i]==a[i-1]){
            continue;
        }else if(a[i]==a[i-1]+1){
            l++;
            max_l=max(max_l,l);
        }else{
            l=1;
        }
    }

    cout<<max_l<<'\n';

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t; cin>>t;
    while(t--) solve();

    return 0;
}