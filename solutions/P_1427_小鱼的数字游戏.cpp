#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> a;
    int x;
    while(cin>>x){
        a.push_back(x);
    }
    int l=a.size();
    for(int i=l-2 ; i>=0 ; i--){
        cout<<a[i]<<" ";
    }
    return 0;
}