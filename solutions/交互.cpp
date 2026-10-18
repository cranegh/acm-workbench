#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin>>n;
    for(int k=1 ; k<=n-1 ; k++){
        int i=2*k-1; int j=2*k;
        cout<<"? "<<i<<" "<<j<<endl;
        int op; cin>>op;
        if(op==-1) return;
        else if(op==1){
            cout<<"! "<<i<<endl;
            return;
        }
    }
    int i=2*n-1; int j=2*n;
    cout<<"? "<<i<<" "<<1<<endl;
    int op; cin>>op;
    if(op==-1) return;
    else if(op==1){
        cout<<"! "<<i<<endl;
        return;
    }
    cout<<"? "<<i<<" "<<2<<endl;
    cin>>op;
    if(op==-1) return;
    else if(op==1){
        cout<<"! "<<i<<endl;
        return;
    }

    cout<<"! "<<j<<endl;


}

int main(){

    int T; cin>>T;
    while(T--) solve();
    
    return 0;
}
