#include<iostream>
#include<algorithm>
#include<set>
#include<cstring>
#include<vector>

using namespace std;
using ll = long long;

struct Node{
    int value;
    Node *next;
};

const int N = 1e6+9;
Node *p[N];

void insertnode(int y , Node* x){
    Node *node = new Node;
    node->value=y;
    node->next=x->next;
    x->next=node;

    p[y]=node;
}

void deletenode(Node *x){
    if(x->next == nullptr) return;
    
    Node *tar = x->next;
    x->next= tar->next;

    delete tar;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    Node *head = new Node;
    head -> value = 1; 
    head -> next = nullptr;
    p[1]=head;

    int _; cin>>_;
    while(_--)
    {
        int op; cin>>op;
        if(op==1){
            int x,y; cin>>x>>y;
            insertnode(y,p[x]);
        }else if(op==2){
            int x; cin>>x;
            if(p[x]->next==nullptr) cout<<0<<'\n';
            else cout<<p[x]->next->value<<'\n';
        }else if(op==3){
            int x; cin>>x;
            deletenode(p[x]);
        }
    }

    return 0;
}