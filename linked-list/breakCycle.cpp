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
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
bool detectcycle(node*head)
{
	node* fast=head;
	node* slow=head;
	while(fast!=NULL && fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
		
		if(slow==fast)
		{
			return true;
		}
	}
	return false;
}
node* new_linkedList(node*head)
{
	node*slow=head;
	node*fast=head;
	node*temp=head;
	while((slow&&fast&&fast->next)!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	while(temp->next!=slow->next)
	{
		temp=temp->next;
		slow=slow->next;
	}
	slow->next=NULL;
	return head;
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
	node*head=takeinput();
	node*ans=new_linkedList(head);
	print(ans);
	return 0;
	
}
