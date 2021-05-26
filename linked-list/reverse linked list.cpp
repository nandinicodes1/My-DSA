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
node* reverse(node* head,int k)
{
	node* current=head;
	node*next=NULL;
	node*prev=NULL;
	int count=0;
	while(current!=NULL && count<k)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		count++;
	}
	if(next!=NULL)
	{
		head->next=reverse(next,k);
	}
	return prev;
}
void insertAtTail(node*&head,int data)
{
	if(head==NULL)
	{
	head=new node(data);
	return;
	}
	node*tail=head;
	while(tail->next!=NULL)
	{
		tail=tail->next;
	}
	tail->next=new node(data);
	return;
}
void buildLinkedList(node*&head)
{
	int data;
	cin>>data;
	while(data!=-1)
	{
		insertAtTail(head,data);
		cin>>data;
	}
}
void print(node* head)
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

int main()
{
	int n,k;
	cin>>n>>k;
	node* head=NULL;
	buildLinkedList(head);
	head=reverse(head,k);
	print(head);
	return 0;
}
