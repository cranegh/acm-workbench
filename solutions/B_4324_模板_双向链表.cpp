#include<iostream>
#include<algorithm>
#include<set>
#include<cstring>
#include<vector>

using namespace std;
using ll = long long;

struct Node{
    int value;
    Node *left;
    Node *right;
};

const int N = 5e5+9;
Node *pos[N];
bool removed[N];

void insertnode_left(int i , Node* k){
    Node *ori_left = k->left;
    
    k->left=pos[i];
    pos[i]->left=ori_left;
    pos[i]->right=k;
    if(ori_left!=nullptr) ori_left->right=pos[i];

}

void insertnode_right(int i , Node* k){
    Node *ori_right = k->right;
    
    k->right=pos[i];
    pos[i]->right=ori_right;
    pos[i]->left=k;
    if(ori_right!=nullptr) ori_right->left=pos[i];

}

void build(int i , Node* k){
    Node *node = new Node;
    node->value=i;

    Node *ori_right = k->right;
    
    k->right=node;
    node->right=ori_right;

    node->left=k;
    if(ori_right!=nullptr) ori_right->left=node;

    pos[i]=node;
}

void unlink(Node *x)
{
    if(x==nullptr) return;

    Node *x_l = x->left;
    Node *x_r = x->right;

    if(x_l!=nullptr) x_l->right=x_r;
    if(x_r!=nullptr) x_r->left=x_l;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    Node *head = new Node;
    head->value = 1;
    head->left = nullptr;
    head->right = nullptr;
    pos[1]=head;

    int n,m; cin>>n>>m;

    int tt=n;

    for(int i=2 ; i<=n ; i++){
        build(i,pos[i-1]);
    }

    for(int i=1 ; i<=m ; i++){
        int op; cin>>op;
        if(op==1){
            int x,y; cin>>x>>y;
            if(x==y) continue;
            unlink(pos[x]);
            insertnode_left(x,pos[y]);

        }else if(op==2){
            int x,y; cin>>x>>y;
            if(x==y) continue;
            unlink(pos[x]);
            insertnode_right(x,pos[y]);
        }else if(op==3){
            int x; cin>>x;
            if(removed[x]) continue;
            removed[x]=true;
            tt--;
        }
    }

    if(tt==0) cout<<"Empty!";
    else{
        Node *start = head;
        while(start->left != nullptr) start=start->left;
        while(start!=nullptr){
            if(!removed[start->value]) cout<<start->value<<' ';
            start=start->right;
        }
    }

    return 0;
}