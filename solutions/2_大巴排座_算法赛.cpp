#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5+9;
int a[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    
    for(int i=1 ; i<=n ; i++) cin>>a[i];
    sort(a+1,a+1+n);
    
    int isNo=0;

    for(int i=1 ; i<=n ; i++){
        if(a[i]<i){
            isNo=1;
            break;
        }
    }

    if(isNo==0) cout<<"YES";
    else cout<<"NO";
}