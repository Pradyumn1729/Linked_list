#include <bits/stdc++.h>

using namespace std;
class node{
  public:
  int data;
  node* next;
  
  public:
  node(int data1,node* next1){
      data=data1;
      next=next1;
  }
  
  public:
  node(int data1){
      data=data1;
      next=nullptr;
  }
};
// node* RemoveHead(node* head){
//     if(head == NULL)  return head;
//     node* temp=head;
//     head=head->next;
//     delete temp;
//     return head;
// }

node* converter(vector<int>&arr){
    node* head=new node(arr[0]);
    node* mover=head;
    for(int i=1;i<arr.size();i++){
        node* temp=new node(arr[i]);
        mover->next=temp;
        mover=mover->next;//or mover=temp
    }
    return head;
}

node* delTail(node* head){
    if(head==NULL || head->next==NULL)  return nullptr;
    node* temp=head;
    while(temp->next->next !=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;

    return head;
}

void print(node* head){
    node* temp1=head;
    while(temp1!=NULL){
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
}
int main(){
    vector<int> arr={1,2,3,4,5};
    node *head= converter(arr);
    head=delTail(head);
    print(head);
    return 0;
}