#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<bitset>
#include<queue>
#include<unordered_map>

using namespace std;
using ll = long long; 

unordered_map<string , int > ump;

int n;
ll ans=0;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int q; cin>>q;
    for(int i=0 ; i<q ; i++){
        int op; cin>>op;
        if(op==1){
            string name; int score;
            cin>>name>>score;
            ump[name]=score;
            cout<<"OK\n";
        }else if(op==2){
            string name; cin>>name;
            if(!ump.count(name)) cout<<"Not found\n";
            else cout<<ump[name]<<'\n';
        }else if(op==3){
            string name; cin>>name;
            if(!ump.count(name)) cout<<"Not found\n";
            else{
                ump.erase(name);
                cout<<"Deleted successfully\n";
            }
        }else if(op==4){
            int tt=ump.size();
            cout<<tt<<'\n';
        }
        
    }

    return 0;
}