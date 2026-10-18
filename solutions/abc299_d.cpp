#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n; cin>>n;
    int l = 1, r = n;
    while(l+1!=r){
        int mid = (l+r)>>1;

        cout<<"? "<<mid<<endl;
        int response; cin>>response;
        if(response == 0) l = mid;
        else r = mid;
    }
    int ans = l;
    cout<<"! "<<ans<<endl;

    return 0;
}