#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		int data;
		node* next;
		node(int data)
		{
			this->data=data;
			this->next=NULL;
		}
};
node* takeinput(int n)
{
	int count=0;
	node*head=NULL,*tail=NULL;
	while(count<n)
	{
		int data;
		cin>>data;
		node* newnode=new node(data);
		if(head==NULL)
		{
			head=newnode;
			tail=newnode;
		}
		else
		{
			tail->next=newnode;
			tail=newnode;	
		}
		count++;
	}
	return head;
}
int getPoint(node*head1,node*head2,int d)
{
	node*a=head1;
	node*b=head2;
	while(d!=0)
	{
		if(a==NULL)
		{
			return -1;
		}
		a=a->next;
		d--;
	}
	while(a!=NULL && b!=NULL)
	{
		if(a==b)
		{
			return a->data;
		}
		a=a->next;
		b=b->next;
	}
	return -1;
}
int intersectionPoint(node* head1,node* head2,int n1,int n2)
{
	int d;
	if(n1>n2)
	{
		d=n1-n2;
		return getPoint(head1,head2,d);
	}
	else
	{
		d=n2-n1;
		return getPoint(head2,head1,d);
	}
}
int main()
{
	int n1;
	cin>>n1;
	node*head1=takeinput(n1);
	int n2;
	cin>>n2;
	node*head2=takeinput(n2);
	cout<<intersectionPoint(head1,head2,n1,n2);
	return 0;
}
