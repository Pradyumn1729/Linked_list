

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
int Len(node* head){
    node* temp=head;
    int count=0;
    while(temp){
        // cout<<temp->data<<" ";
        temp=temp->next;
        count++;
    }
    return count;
}
int main()
{
    // cout<<"Hello World";
   vector<int>arr={5,15,8,7};
   node *head= converter(arr);
//   cout<<head->data;
   node* temp1=head;
   int count=0;
   while(temp1){
       cout<<temp1->data<<" ";
       temp1=temp1->next;
   }
   cout<<endl;
   cout<<"length is "<<Len(head);
    return 0;
}
