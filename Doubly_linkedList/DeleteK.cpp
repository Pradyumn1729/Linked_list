#include <bits/stdc++.h>
using namespace std;
class node{
  public:
  int data;
  node* next;
  node* back;

  public:
  node(int data1,node* next1,node* back1){
      data=data1;
      next=next1;
      back=back1;
  }
  
  public:
  node(int data1){
      data=data1;
      next=nullptr;
      back=nullptr;
  }
};
node* converter(vector<int>& arr){
    node* head=new node(arr[0]);
    node* prev=head;
    for(int i=1;i<arr.size();i++){
        node* temp=new node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

node* DelHead(node* head){
    if(head==NULL || head->next==NULL)
        return NULL;
    node* prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;
    return head;
    
}

node* DeleteTail(node* head){
    node* tail=head;
   
    while(tail->next!=NULL){
        tail=tail->next;
    }
    node* prev=tail->back;
    tail->back=nullptr;
    prev->next=nullptr;
    delete tail;
    return head;
}

node* DeleteK(node* head,int k){
    if(head==NULL)
        return NULL;

    int cnt=0;
    node* temp=head;
    while(temp->next!=NULL){
        cnt++;
        if(cnt==k)
            break;
        temp=temp->next;
    }
    node* prev=temp->back;
    node* front=temp->next;
    
    if(prev==NULL && front==NULL)
        return NULL;
    
    if(front==NULL)
        return DeleteTail(head);

    if(prev==NULL)
        return DelHead(head);

    front->back=prev;
    prev->next=front;
    temp->next=NULL;
    temp->back=NULL;
    delete temp;
    return head;
}
void print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
   vector<int>arr={7,6,5,8,9};
   node *head= converter(arr);
   head=DeleteK(head,5);
   print(head);
    return 0;
}