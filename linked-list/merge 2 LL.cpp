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
node* takeinput(int n){
	int count=0;
    node* head=NULL,*tail=NULL;
    while(count<n){
    	int data;
    	cin>>data;
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        count++;
    }
    return head;
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
	if(a->data < b->data){
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
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n1;
		cin>>n1;
		node*head1=takeinput(n1);
		int n2;
		cin>>n2;
		node*head2=takeinput(n2);
		node*head=merge(head1,head2);
		print(head);
	}
	return 0;
}
