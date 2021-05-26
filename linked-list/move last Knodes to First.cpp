#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *newNode(int k){
    Node *temp=new Node;
    temp->data=k;
    temp->next=NULL;
    return temp;
}

Node *addNode(Node *head,int k){
    if(head==NULL)
     head=newNode(k);
    else{
        Node*temp=head;
        Node*node=newNode(k);
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=node;
    }
  return head;
}

Node *CreateLinkedList(int n){
    int data;
    Node*head=NULL;
    while(n--){
        cin>>data;
        head=addNode(head,data);
    }
  return head;
}

Node *moveLastKNodes(Node *head,int n,int k){
   if(k==0)
   return head;
   
   Node *temp=head;
   Node *x;
   int count=1;
   while(temp->next!=NULL){
       if(count==n-k)
       x=temp;
       temp=temp->next;
        count++;
    }
   temp->next=head;
   head=x->next;
   x->next=NULL;
   return head;
 
}

int main(){
    int n{};
    int k{};
    cin>>n;
    Node *head=CreateLinkedList(n);
    cin>>k;
    head=moveLastKNodes(head,n,k%n);
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;    
}
