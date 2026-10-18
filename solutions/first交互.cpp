#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    for(int i=0 ; i<100 ; i++){
        cout<<"? "<<i<<endl;
        int response; cin>>response;
        if(response!=0){
            cout<<"! "<<i<<endl;
            return 0;
        }
    }

    cout<<'!'<<100<<endl;

    return 0;
}