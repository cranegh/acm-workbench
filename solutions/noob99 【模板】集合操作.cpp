#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> s;
    int y;
    cin>>y;
    while(y--){
    int op;
    cin>>op;
    switch(op){
        case 1:{ 
        int x;
        cin>>x;
        s.insert(x);
        break;
        }
        case 2:{
        int m;
        cin>>m;
        s.erase(m);
        break;
        }
        case 3:{
        int n;
        cin>>n;
        if(s.find(n)!=s.end()) cout<<"YES\n";
        else cout<<"NO\n";
        break;
        }
        case 4:{
        cout<<s.size()<<endl;
        break;
        }
        case 5:{
        int o;
        cin>>o;
        auto i=s.lower_bound(o);
        if(i==s.begin()) cout<<-1<<endl;
        else{
        i--;
        cout<<*i<<endl;
        }
        break;
        }
        case 6:{
        int p;
        cin>>p;
        auto j=s.upper_bound(p);
        if(j==s.end()) cout<<-1<<endl;
        else{
        cout<<*j<<endl;
        break;
        }
        }
    }
}
    return 0;
}
