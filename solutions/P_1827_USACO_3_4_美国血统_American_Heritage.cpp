#include<iostream>

using namespace std;
using ll = long long;

void work(string in_or , string pre_or){
    if(in_or.size()==0) return;
    
    char root = pre_or[0];
    int len=in_or.find(root);

    string l_ior=in_or.substr(0,len);
    string l_preor=pre_or.substr(1,len);

    string r_ior=in_or.substr(len+1);
    string r_por=pre_or.substr(len+1);

    work(l_ior,l_preor);
    work(r_ior,r_por);
    cout<<root;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string in_or; cin>>in_or;
    string pre_or; cin>>pre_or;

    work(in_or,pre_or);

    return 0;
}