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
node* RemoveHead(node* head){
    if(head == NULL)  return head;
    node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

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

node* DeleteK(node* head,int k){
    if(head==NULL) return head;
    if(k==1){
        node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    node* temp=head;
    node* ptr=NULL;
    int count=0;
    while(temp){
        count++;
        if(count==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
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
    head=RemoveHead(head);
    print(head);
    return 0;
}