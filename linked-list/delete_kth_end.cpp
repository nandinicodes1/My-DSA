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
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(count!=n){
        node *newnode=new node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
        count++;
    }
    return head;
}

node* kthnode(node*head,int k){
	node* fast=head;
	node* slow=head;
	while(k!=0){
	fast=fast->next;
	k--;
	}
	while(fast->next!=NULL){
	fast=fast->next;
	slow=slow->next;
	}
	node* temp=slow->next;
	slow->next=slow->next->next;
	delete temp;

	return head;
}

void print(node* head){
	
	node* temp=head;
	
	while(temp!=NULL){
		
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}


int main(){
int n,k;
cin>>n>>k;
node* head=NULL;
head=takeinput(n);
node* ans=kthnode(head,k);
print(ans);
return 0;

	
}
