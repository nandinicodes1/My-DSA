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
/*
class linkedList()
{
	node*head;
	node*tail;
public:
	linkedList()
	{
		head=NULL;
		tail=NULL;
	}
	void insert()
	{
		
	}
		
}*/
int length(node*head)
{
	int len=0;
	node*temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		len+=1;
	}
	return len;
}
void insertAtHead(node*&head,int data)
{
	node*n=new node(data);
	n->next=head;
	head=n;
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
void insertAtMiddle(node*&head,int data,int p)
{
	if(head==NULL||p==0)
	return insertAtHead(head,data);
	else if(p>length(head))
	{
		return insertAtTail(head,data);
	}
	else
	{
		int jump=0;
		node*temp=head;
		while(jump!=p-1)
		{
			temp=temp->next;
			jump+=1;
		}
		
		node*n=new node(data);
		n->next=temp->next;
		temp->next=n;
	}
}
void print(node*head)
{
	node*temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
}
void deleteAtHead(node*&head)
{
	if(head==NULL)
	{
		return;
	}
	node*temp=head;
	head=head->next;
	delete temp;
	return;	
}
void deleteAtTail(node*&head)
{
	node*prev=NULL;
	node*temp=head;
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	delete temp;
	prev->next=NULL;
}
void deleteInMiddle(node*&head,int p)
{
	int jump=0;
	node*temp=head;
	node*prev=NULL;
	while(jump!=p)
	{
		prev=temp;
		temp=temp->next;
		
	}
	prev->next=temp->next;
	delete temp;
	return;
}
bool searchRecursive(node*head,int key)
{
	if(head==NULL)
	{
		return false;
	}
	if(head->data==key)
	{
		return true;
	}
	else{
		return searchRecursive(head->next,key);
	}
}
bool searchIterative(node*head,int key)
{
	if(head==NULL)
	{
		return false;
	}
	while(head!=NULL)
	{
		if(head->data==key){
			return true;
		}
		head=head->next;
	}
	return false;
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
void reverse(node*&head)
{
	node*C=head;
	node*P=NULL;
	node*N;
	while(C!=NULL)
	{
		N=C->next;
		C->next=P;
		P=C;
		C=N;
	}
	head=P;
}
node* reverseRec(node*head)
{
	if(head->next==NULL||head==NULL)
	{
	return head;
	}
	node*smallHead=reverseRec(head->next);
	node*C=head;
	C->next->next=C;
	C->next=NULL;
	return smallHead;
}
node* midPoint(node*head)
{
	if(head->next==NULL||head==NULL)
	{
		return head;
	}
	node*slow=head;
	node*fast=head->next;
	while(fast->next!=NULL&&fast!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}
node* KthNode(node*head,int k)
{
	node*fast=head;
	node*slow=head;
	while(k!=0)
	{
		fast=fast->next;
		k--;
	}
	while(fast->next==NULL)
	{
		fast=fast->next;
		slow=slow->next;
	}
	return slow;
}
node* merge(node* a,node* b)
{
	if(a==NULL)
	{
		return b;
	}
	else if(b==NULL){
		return a;
	}
	node*c;
	if(a->next<b->next){
		c=a;
		c->next=merge(a->next,b);
	}
	else
	{
		c=b;
		c->next=merge(a,b->next);
	}
	return c;
}
int main()
{
	node*head=NULL;
	insertAtHead(head,6);
	insertAtHead(head,5);
	insertAtHead(head,4);
	insertAtHead(head,3);
	print(head);
	cout<<endl;
	/*
	insertAtTail(head,7);
	insertAtMiddle(head,10,3);
	print(head);
	cout<<endl;

	deleteAtHead(head);
	deleteAtTail(head);
	print(head);

	deleteInMiddle(head,1);
	print(head);
	/*
	if(searchRecursive(head,4)){
		cout<<"element is present!\n";
	}
	else
	cout<<"not present!";
	
	if(searchIterative(head,14)){
		cout<<"element is present!\n";
	}
	else
	cout<<"not present!";
	
	buildLinkedList(head);
	print(head);
	
	reverse(head);
	print(head);
	
	head=reverseRec(head);
	print(head);
	cout<<endl;
	node*m=midPoint(head);
	cout<<m->data;
	cout<<endl;
	
	node*s=KthNode(head,3);
	cout<<s->data;
	*/
	node*head1=NULL;
	node*head2=NULL;
	cin>>head1>>head2;
	cout<<head1<<endl<<head2;
	head=merge(head1,head2);
	cout<<head;
	return 0;
}
