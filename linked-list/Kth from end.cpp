#include<iostream>
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
node* KthnodeFromEnd(node*head,int k)
{
	node*fast=head;
	node*slow=head;
	while(k!=0)
	{
		fast=fast->next;
		k--;
	}
	while(fast!=NULL)
	{
		fast=fast->next;
		slow=slow->next;
	}
	return slow;
}
int main()
{
	node*head=NULL;
	head=takeinput();
	int k;
	cin>>k;
	node* a=KthnodeFromEnd(head,k);
	cout<<a->data;
	return 0;
}
