#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		int data;
		node* next;
		//constructor
		node(int d)
		{
			data=d;
			next =NULL;
		}
};

// insertion in circular ll
void insert(node*&head,int data){
	node* n=new node(data);
	node* temp=head;
	
	n->next=head;
	if(temp!=NULL){
		while(temp->next!=head){
			temp=temp->next;
		}
		temp->next=n;
	}else{
		n->next=n;
	}
	head=n;
}

node* getnode(node* head,int data){
	node *temp=head;
	//for all nodes except for the last node
	while(temp->next!=head){
		if(temp->data==data){
			return temp;
		}
		temp=temp->next;
	}
	//out of the loop-- checking for the tail node 
	if(temp->data==data){
		return temp;
	}
	return NULL;
}

void deleteNode(node*&head,int data){
	node* del=getnode(head,data);
	if(del==NULL){
		return;
	}
	//if deleted node is head
	if(del==head){
		head=head->next;
	}
	
	node* temp=head;
	//stop 1 step behind the node to be deleted
	while(temp->next!=del){
		temp=temp->next;
	}
	temp->next=del->next;
	delete del;
}

void print(node*head){
	node *temp=head;
	while(temp->next!=head){
		cout<<temp->data<< "-->";
		temp=temp->next;
	}
	cout<<temp->data;
	return;
}

int main(){
	node *head=NULL;
	insert(head,1);
	insert(head,2);
	insert(head,3);
	insert(head,4);
	insert(head,5);
	print(head);
	cout<<endl;
	deleteNode(head,1);
	print(head);
	return 0;
}
