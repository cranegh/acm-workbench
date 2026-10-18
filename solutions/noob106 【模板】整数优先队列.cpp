#include<queue>
#include<iostream>
using namespace std;
int main(){
    priority_queue<int> s;
    int n;
    cin>>n;
    while(n--){
        int op;
        cin>>op;
        switch(op){
            case 1:{
                int x;
                cin>>x;
                s.push(-x);
                break;
            }
            case 2:{
                cout<<-s.top()<<endl;
                break;
            }
            case 3:{
                s.pop();
                break;
            }
        }
    }
    return 0;
}
