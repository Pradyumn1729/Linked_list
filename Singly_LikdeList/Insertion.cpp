//contains both the insertor at beginning also and at the end also;
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
    node* prev=NULL;
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


node* DeleteEle(node* head,int ele){
    if(head==NULL) return head;
    if(head->data==ele){
        node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    node* temp=head;
    node* prev=NULL;
    // int count=0;
    while(temp){
        // count++;
        if(temp->data==ele){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
node* InsertorBeg(node* head,int val){
    // node* temp=new node(val,head);
    // return temp;
    //or method then that of above 
    return new node(val,head);
}
node* InsertorEnd(node* head,int val){
   if(head==NULL){
     return new node(val);
   }
   node* temp= head;
   while(temp->next!=NULL){      //if u take while(temp) it would be wrong as it wll make it as out of range thts y temp->next=NULL 
    temp=temp->next;
   }
   node* NewNode=new node(val);
   temp->next=NewNode;
   return head;
}

node* Insertpos(int k,int ele,node* head){
    if(head==NULL){
    //    return InsertorBeg(head,ele);
        if(k==1){
            // node* temp = new node(ele,head);
            // return temp;
            return new node(ele);
        }
        else{
            return head;
        }
    }
    if(k==1){
        return new node(ele,head);
    }
    
     int count=0;
     node* temp=head;
     while(temp!=NULL){
        count++;
        if(count==(k-1)){
            node* x=new node(ele,temp->next);
            temp->next=x;
            break;
        }
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
    // head=RemoveHead(head);
    // head=DeleteK(head,3);//this is to remove according to position 
    // head=DeleteEle(head,4);//this is to remove according to element;
    // head=InsertorEnd(head,0);//function to insert the in to the head orbe beginning 

    // below will be function to insert at given kth positon ,but we the size will be n+1 now 
        head=Insertpos(1,59,head);
    print(head);
    return 0;
}