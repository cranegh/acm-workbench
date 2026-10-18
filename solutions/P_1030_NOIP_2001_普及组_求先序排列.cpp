#include<iostream>

using namespace std;
using ll = long long;

void work(string in_or , string po_or){
    if(in_or.size()==0) return;
    
    char root = po_or[po_or.size()-1];
    int len=in_or.find(root);

    string l_ior=in_or.substr(0,len);
    string l_por=po_or.substr(0,len);

    string r_ior=in_or.substr(len+1);
    string r_por=po_or.substr(len,po_or.size()-len-1);

    cout<<root;
    work(l_ior,l_por);
    work(r_ior,r_por);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string in_or; cin>>in_or;
    string po_or; cin>>po_or;

    work(in_or,po_or);

    return 0;
}