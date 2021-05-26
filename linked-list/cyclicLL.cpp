#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
    
    node(int x){
        data=x;
        next=NULL;
    }
};


node *takeInput(){
    int input;;
    node *head=NULL;
    node *tail=NULL;
    while(1){
        cin>>input;
        if(input==-1)
            break;
            
        node *newnode=new node(input);
        
        if(head==NULL){
          head=newnode;
          tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    return head;
}

node* iterativeSearch(node* head,int key){

  node* temp = head;
  while(temp!=NULL){

    if(temp->data == key)
      return temp;

    temp = temp->next;
  }
  return NULL;
}

void result(node *head)
{ 
    node *temp=head,*dup=NULL;
    while(temp!=NULL){
        dup=iterativeSearch(temp->next,temp->data);
        if(dup!=NULL)
            break;
        temp=temp->next;
    }
    
    while(temp->next->data!=dup->data)
        temp=temp->next;
    temp->next=NULL;
    
     node *t=head;
   while(t)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
    
    
}



int main(){
    node *head=takeInput();
    
    result(head);    
    return 0;
}
