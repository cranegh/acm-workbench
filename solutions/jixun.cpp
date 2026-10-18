#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

vector<int> v;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n,m; cin>>n>>m;
    for(int i=1 ; i<=n ; i++){
        int temp; cin>>temp;
        v.push_back(temp);
    }

    while(m--){
        int op; cin>>op;
        if(op==1){
            int l1; cin>>l1;
            vector<int> berep;
            for(int i=1 ; i<=l1 ; i++){
                int temp; cin>>temp;
                berep.push_back(temp);
            }

            int l2; cin>>l2;
            vector<int> torep;
            for(int i=1 ; i<=l2 ; i++){
                int temp; cin>>temp;
                torep.push_back(temp);
            }

            auto it = search(v.begin(),v.end(),berep.begin(),berep.end());
            if(it!=v.end()){
                int index=it-v.begin();
                v.erase(v.begin()+index,v.begin()+index+l1);
                v.insert(v.begin()+index,torep.begin(),torep.end());
            }

        }else if(op==2){
            for(int i=0 ; i<v.size()-1 ; ){
                if((v[i]+v[i+1])%2==0){
                    v.insert(v.begin()+i+1,(v[i]+v[i+1])/2);
                    i+=2;
                }else{
                    i++;
                }
            } 
        }else if(op==3){
            int l,r; cin>>l>>r;
            reverse(v.begin()+l-1,v.begin()+r);
        }
    }

    for(int i=0 ; i<v.size() ; i++){
        cout<<v[i];
        if(i<v.size()-1) cout<<' ';
    }

    return 0;
}


