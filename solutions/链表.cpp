#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode (int x){
        val=x;
        next=nullptr;
    }
};
int a[]={1,3,5,7,9};
int main(){
    ListNode* head= new ListNode(a[0]);
    ListNode* tail=head;
    for(int i=1; i<5 ;i++){
        ListNode* tmp=new ListNode(a[i]);
        tail->next=tmp;
        tail=tmp;
    }
    auto p=head;
    while(p!=nullptr){
        cout<<p->val<<" ";
        p=p->next;
    }
}