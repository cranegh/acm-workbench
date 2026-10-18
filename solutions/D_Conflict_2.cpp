#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

const int N =5e5+9;
string s[N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,q; cin>>n>>q;

    string server="";

    for(int i=0 ; i<q ; i++){
        int op; cin>>op;
        if(op==1){
            int p; cin>>p;
            s[p]=server;
        }else if(op==2){
            int p; string ss;
            cin>>p>>ss;
            s[p]+=ss;
        }else if(op==3){
            int p; cin>>p;
            server=s[p];
        }
    }

    cout<<server;
    
    return 0;
}