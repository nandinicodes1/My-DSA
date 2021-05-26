#include <iostream>
using  namespace std;
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
node* takeinput(int n){
    int data;
    int count=0;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(count<n){
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
        count++;
    }
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
void oddEven(node*&head)
{
	node*current=head;
	node*prev=NULL;
	node*end=head;
	while(end->next!=NULL)
	{
		end=end->next;	
	}	
	node* new_end=end;
	while(current->data % 2==0 && current!=end)
	{
		new_end->next=current;
		current=current->next;
		new_end->next->next=NULL;
		new_end=new_end->next;
	}
	if(current->data%2!=0)
	{
		head=current;
		while(current!=end)
		{
			if(current->data%2!=0)
			{
				prev=current;
				current=current->next;
			}
			else
			{
				prev->next=current->next;
				current->next=NULL;
				new_end->next=current;
				new_end=current;
				current=prev->next;
			}
		}
	}
	else
	{
		prev=current;
	}
	if(new_end!=end && (end->data)%2==0)
	{
		prev->next=end->next;
		end->next=NULL;
		new_end->next=end;
	}
	return;
	
}
int main()
{
	int n;
	cin>>n;
    node* head=takeinput(n);
    oddEven(head);
    print(head);
    return 0;
}

