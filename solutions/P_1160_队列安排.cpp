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

const int N = 1e5+9;
Node *pos[N];
bool removed[N];

void insertnode_left(int i , Node* k){
    Node *node = new Node;
    node->value=i;

    Node *ori_left = k->left;
    
    k->left=node;
    node->left=ori_left;

    node->right=k;
    if(ori_left!=nullptr) ori_left->right=node;

    pos[i]=node;
}

void insertnode_right(int i , Node* k){
    Node *node = new Node;
    node->value=i;

    Node *ori_right = k->right;
    
    k->right=node;
    node->right=ori_right;

    node->left=k;
    if(ori_right!=nullptr) ori_right->left=node;

    pos[i]=node;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    Node *head = new Node;
    head->value = 1;
    head->left = nullptr;
    head->right = nullptr;
    pos[1]=head;

    int n; cin>>n;
    for(int i=2 ; i<=n ; i++){
        int k,p; cin>>k>>p;
        if(p==0) insertnode_left(i,pos[k]);
        else if(p==1) insertnode_right(i,pos[k]);
    }
    int m; cin>>m;
    for(int i=1 ; i<=m ; i++){
        int x; cin>>x;
        removed[x]=true;
    }

    Node *start = head;
    while(start->left!=nullptr) start = start->left;
    
    while(start!=nullptr){
        if(!removed[start->value]) cout<<start->value<<' ';
        start = start->right;
    }

    return 0;
}