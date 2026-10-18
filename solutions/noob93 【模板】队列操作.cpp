#include<iostream>
#include<queue>
using namespace std;
int main(){
    int n;
    cin>>n;
    queue<int> s;
    while(n--){
        int op;
        cin>>op;
        switch(op){
            case 1: 
            int x;
            cin>>x;
            s.push(x);
            break;
            case 2:
            if(s.empty()) cout<<"ERR_CANNOT_POP\n";
            else s.pop();
            break;
            case 3:
            if(s.empty()) cout<<"ERR_CANNOT_POP\n";
            else cout<<s.front()<<endl;
            break;
            case 4:
            cout<<s.size()<<endl;
            break;
        }
    }
}
    

