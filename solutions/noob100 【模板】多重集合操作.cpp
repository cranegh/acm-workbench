#include<iostream>
#include<set>
using namespace std;
int main(){
    multiset<int> s;
    int n;
    cin>>n;
    while(n--){
        int op;
        cin>>op;
        if(op==1){
            int x;
            cin>>x;
            s.insert(x);
        }
        if(op==2){
            int x;
            cin>>x;
            s.erase(s.find(x));
        }
        if(op==3){
            int x;
            cin>>x;
            cout<<s.count(x)<<endl;
        }
        if(op==4){
            cout<<s.size()<<endl;
        }
        if(op==5){
            int x;
            cin>>x;
            auto it=s.lower_bound(x);
            if(it==s.begin()) cout<<-1<<endl;
            else{
                it--;
                cout<<*it<<endl;
            }
        }
        if(op==6){
            int x;
            cin>>x;
            auto it=s.upper_bound(x);
            if(it==s.end()) cout<<-1<<endl;
            else cout<<*it;
        }
    }
}