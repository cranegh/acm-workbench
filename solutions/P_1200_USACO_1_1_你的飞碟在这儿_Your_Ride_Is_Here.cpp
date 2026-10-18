#include<iostream>
using namespace std;
int main(){
    string p,t;
    cin>>p>>t;
    int np=1,nt=1;
    for (int i=0 ; i<p.length() ; i++){
        np*=p[i]-'A'+1;
    }
    for (int i=0 ; i<t.length() ; i++){
        nt*=t[i]-'A'+1;
    }
    int ap=np%47,at=nt%47;
    if (ap==at) cout<<"GO";
    else cout<<"STAY";
    return 0;
}